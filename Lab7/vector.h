#pragma once

template <class T>
class Vector {
	unsigned long MAX_SIZE;
	unsigned long size;
	T* v;
public:
	Vector();
	void Push(T new_element);
	T& Pop();
	void Delete(unsigned long index);
	void Insert(T new_element, unsigned index);
	void Sort(bool (*callback)(T& a, T& b) = nullptr);
	T& Get(unsigned long index);
	void Set(T element, unsigned index);
	unsigned long Count();
	long long firstIndexOf(T parameter, bool(*callback)(T a, T b) = nullptr);
};

template<class T>
inline Vector<T>::Vector() {
	MAX_SIZE = 1;
	size = 0;
	v = new T[MAX_SIZE];
}

template<class T>
inline void Vector<T>::Push(T new_element)
{
	if (size + 1 < MAX_SIZE) {
		v[size] = new_element;
		size++;
	}
	else {
		T* copy = new T[MAX_SIZE];
		for (unsigned i = 0; i < MAX_SIZE; i++)
			copy[i] = v[i];
		
		v = new int[MAX_SIZE * 2];
		MAX_SIZE = MAX_SIZE * 2;
		
		for (unsigned i = 0; i < size; i++)
			v[i] = copy[i];
		
		v[size] = new_element;
		size++;
	}
}

template<class T>
inline T& Vector<T>::Pop()
{
	return v[--size];
}

template<class T>
inline void Vector<T>::Delete(unsigned long index)
{
	if (index >=0 && index < size) {
		for (unsigned i = index; i < size; i++)
			v[i] = v[i + 1];
		size--;
	}
}

template<class T>
inline void Vector<T>::Insert(T new_element, unsigned index)
{
	if (index >= 0 && index <= size)
	{
		if (size + 1 >= MAX_SIZE)
		{
			T* copy = new T[MAX_SIZE];
			for (unsigned i = 0; i < MAX_SIZE; i++)
				copy[i] = v[i];

			v = new int[MAX_SIZE * 2];
			MAX_SIZE = MAX_SIZE * 2;

			for (unsigned i = 0; i < size; i++)
				v[i] = copy[i];
		}
		for (unsigned i = size; i > index; i--)
			v[i] = v[i - 1];
		v[index] = new_element;
		size++;
	}
}

template<class T>
inline void Vector<T>::Sort(bool(*callback)(T& a, T& b))
{
	int ultim, n1, i;
	ultim = size - 1;
	while (ultim > 0)
	{
		n1 = ultim - 1;
		ultim = 0;
		for (i = 0; i <= n1; i++)
			if ((v[i] < v[i + 1] && callback==nullptr) || (callback!=nullptr && !callback(v[i],v[i+1])))
			{
				T aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				ultim = i;
			}
	}
}

template<class T>
inline T& Vector<T>::Get(unsigned long index)
{
	return v[index];
}

template<class T>
inline void Vector<T>::Set(T element, unsigned index)
{
	if (index >= 0 && index < size)
	{
		v[index] = element;
	}
}

template<class T>
inline unsigned long Vector<T>::Count()
{
	return size;
}

template<class T>
inline long long Vector<T>::firstIndexOf(T parameter, bool(*callback)(T a, T b))
{
	for (unsigned i = 0; i < size; i++)
		if ((callback == nullptr && v[i] == parameter) || (callback != nullptr && callback(v[i], parameter))) return i;
	return -1;
}
