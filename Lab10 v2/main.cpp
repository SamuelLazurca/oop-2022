#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <functional>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string_view>

using namespace std;

class CommandManager {
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(string name, function<void(vector<string>)> fn);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
    void run();
};

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}

void CommandManager::run()
{
    string cmdline;

    getline(cin, cmdline);

    while (cmdline != "stop")
    {
        size_t last, begin, end;
        string comanda;
        vector<string> args;

        if (cmdline.size() != 0)
        {
            last = cmdline.size() - 1;
            end = 0;

            bool ok = false;

            while (end < last)
            {
                begin = cmdline.find_first_not_of(" ", end);
                end = cmdline.find_first_of(" ", begin + 1);

                if (!ok)
                {
                    if (commands.find(cmdline.substr(begin, end - begin)) != commands.end()) {
                        ok = true;
                        comanda = cmdline.substr(begin, end - begin);
                    }
                }
                else args.push_back(cmdline.substr(begin, end - begin));
            }

            if (ok) commands[comanda](args);
        }
        getline(cin, cmdline);
    }
}

bool Sort(string s1, string s2)
{
    return s1.size() < s2.size();
}

int main() {
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;

    // prints pong!
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    auto count = [](vector<string> args) { printf("%d\n", args.size()); };
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [&number_of_errors](vector<string> args) {
        fstream file;

        file.open(args[0], std::ios_base::app | std::ios_base::in);

        if (file.is_open())
        {
            for (int i = 1; i < args.size(); i++)
                file << args[i] << " ";
        }
        else number_of_errors++;

        file.close();
    };
    manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda

    auto times = [cnt = 0](vector<string> args) mutable{
        cnt++;
        printf("%d\n", cnt);
    };
    manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    auto copy = [&number_of_errors](vector<string> args) {
        FILE* in, * out;

        if (NULL == (in = fopen(args[0].c_str(), "rb"))) number_of_errors++;
        if (NULL == (out = fopen(args[1].c_str(), "wb"))) number_of_errors++;

        char buffer[4096];
        size_t i, o;
        i = 1;
        while (i != 0)
        {
            i = fread(buffer, 1, 4096, in);
            o = fwrite(buffer, 1, i, out);
            if (i != o) {
                number_of_errors++;
                return;
            }

        }
    };
    manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards
    auto sort_size = [](vector<string> args)
    {
        auto print = [](string s) { cout << s << " "; };

        std::sort(args.begin(), args.end(), Sort);

        for_each(args.begin(), args.end(), print);

        cout << endl;
    };
    manager.add("sort_size", sort_size);

    // add one more command of anything you'd like

    manager.run();

    printf("number of errors: %u\ndone!\n", number_of_errors);
}
