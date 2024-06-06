#include <iostream>
#include <cstdlib>

//done done in unifide call syntax Age.it all have.it all have. 
//mmmmhhhh.memory allocater's bug is continue to not solve? in vs2022

template<class T>
struct Memory
{
	T* P = NULL;
	size_t N = 0;

};

template <class T>
Memory<T> MemoryAlloc(size_t N) {
	Memory<T> R;
	R.N = N;
	R.P = (T*)calloc(N,sizeof(T));
	return R;
}
template<class T>
Memory<T> MemoryReAlloc(Memory<T>* In, size_t N) {
	size_t X = N * sizeof(In->P);
	void* P = realloc(In->P,X);
	
	Memory<T> R=(*In);

	if (P == NULL) { return *In; }

	if(P == In->P){
		R.N = X;
	}
	else {
		MemoryDeAlloc(In);
		R.P = (T*)P;
		R.N = X;
	}

	return R;
}
template<class T>
bool MemoryDeAlloc(Memory<T>* In) {
	free(In->P);
	In->N = 0;
	In->P = NULL;
	return true;
}

template<class T>
size_t AllocSize(Memory<T>* In) {
	return In->N;
}
template<class T>
T* MemoryIndex(Memory<T>* In, size_t N) {
	if (In->N <= N)return NULL;
	return In->P[N];
}

template<class T>
struct  Vector
{
	Memory<T> M;
	intmax_t Use = 0;
};
template <class T>
bool Push(Vector<T>* In,T* I){
	if (In->Use >= In->M.N) return true;
	In->M.P[In->Use] = *I;
	In->Use++;
	return true;
}

template <class T>
bool Pop(Vector<T>* In) {
	if (In->Use == 0) return false;
	In->Use--;

	return true;
}

template<class T>
size_t Size(Vector<T>* In) {
	return In->Use;
}

template<class T>
T* Index(Vector<T>* In,size_t N) {
	if (In->Use <= N) return NULL;
	return In->M[N];
}

int main() {
	Memory<int> M = MemoryAlloc<int>(16);

	Memory<int> R = MemoryReAlloc(&M, 32);

	//M->Index(8);in unifide call syntax age.

	MemoryDeAlloc(&M);
}