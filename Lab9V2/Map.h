#pragma once

template<class T1, class T2>
struct map {
    T1 key;
    T2 value;
};

template<class T1, class T2>
struct r_map {
    T1 key;
    T2 value;
    unsigned index;
};

template<class T1, class T2>
class MyIterator {
public:
    map<T1, T2>* m;
    unsigned index;

    MyIterator<T1, T2>& operator++() { m++; index++; return *this; }
    bool operator != (MyIterator<T1, T2>& p) { return m != p.m; }
    r_map<T1, T2> operator* () { return { m->key,m->value,index }; }
};

template<class T1, class T2>
class Map {
public:
    map<T1, T2> M[50];
    unsigned count;

    Map();
    Map(T2* string);

    void Set(T1 key, T2 value);
    bool Get(const T1& key, T2& value);
    unsigned Count();
    void Clear();
    bool Includes(const Map<T1, T2>& map);

    void operator=(T2 string);
    T2& operator[](T1 key);
    MyIterator<T1, T2> begin();
    MyIterator<T1, T2> end();
};

template<class T1, class T2>
inline Map<T1, T2>::Map()
{
    count = 0;
}

template<class T1, class T2>
inline Map<T1, T2>::Map(T2* string)
{
    strcpy_s(M[count].value, string);
    count++;
}

template<class T1, class T2>
inline void Map<T1, T2>::Set(T1 key, T2 value)
{
    for (int i = 0; i < count; i++)
        if (M[i].key == key) {
            M[i].value = value;
            return;
        }
}

template<class T1, class T2>
inline bool Map<T1, T2>::Get(const T1& key, T2& value)
{
    for (int i = 0; i < count; i++)
    {
        if (M[i].key == key) {
            value = M[i].value;
            return true;
        }
    }
    return false;
}

template<class T1, class T2>
inline unsigned Map<T1, T2>::Count()
{
    return count;
}

template<class T1, class T2>
inline void Map<T1, T2>::Clear()
{
    for (int i = 0; i < count; i++)
    {
        M[i].key = NULL;
        M[i].value = 0;
    }
    count = 0;
}

template<class T1, class T2>
inline bool Map<T1, T2>::Includes(const Map<T1, T2>& map)
{
    for (int i = 0; i < count; i++)
    {
        bool ok = false;
        for (int j = 0; j < map.count && ok == false; j++)
            if (M[i].key == map.M[i].key && map.M[i].value == M[i].value) ok = true;
        if (ok == false) return false;
    }
    return true;
}

template<class T1, class T2>
inline void Map<T1, T2>::operator=(T2 string)
{
    strcpy_s(this, string);
}

template<class T1, class T2>
inline T2& Map<T1, T2>::operator[](T1 key)
{
    for (int i = 0; i < count; i++)
        if (M[i].key == key) return M[i].value;
    
    M[count].key = key;
    count++;
    return M[count - 1].value;
}

template<class T1, class T2>
inline MyIterator<T1, T2> Map<T1, T2>::begin()
{
    MyIterator<T1, T2> tmp;
    tmp.m = &M[0];
    tmp.index = 0;
    return tmp;
}

template<class T1, class T2>
inline MyIterator<T1, T2> Map<T1, T2>::end()
{
    MyIterator<T1, T2> tmp;
    tmp.m = &M[count];
    tmp.index = this->count;
    return tmp;
}

