#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>
namespace vctr{
	template <class T>
	class VectIt{
	private:
		T* cur;
	public:
		VectIt() : cur(nullptr) {}
		VectIt(T* obj) : cur(obj) {}
		T& operator * () const;
		T* operator -> () const;
		T& operator [] (int pos) const;
		VectIt& operator ++ ();
		VectIt operator ++(int);
		VectIt operator +(int t) const;
		VectIt operator -(int t) const;
		int operator == (const VectIt& cmp) const;
		int operator != (const VectIt& cmp) const;
	};
	template<class T>
	T& VectIt<T>::operator * () const{
		if (!cur){
			throw std::domain_error("Указатель на NULL");
		}
		return *cur;
	}
	template<class T>
	T* VectIt<T>::operator -> () const{
		return cur;
	}
	template<class T>
	T& VectIt<T>::operator [] (int pos) const {
		if (!cur){
			throw std::domain_error("Указатель на NULL");
		}
		return *(cur + pos);
	}
	template<class T>
	VectIt<T>& VectIt<T>:: operator ++ () {
		++cur;
		return (*this);
	}
	template<class T>
	VectIt<T> VectIt<T>:: operator ++(int){
		VectIt<T> res(*this);
		++cur;
		return res;
	}
	template<class T>
	VectIt<T> VectIt<T>::operator +(int t) const{
		return VectIt<T>(cur + t);
	}
	template<class T>
	VectIt<T> VectIt<T>::operator -(int t) const{
		return VectIt<T>(cur - t);
	}
	template<class T>
	int VectIt<T>:: operator == (const VectIt<T>& cmp) const{
		return cur == cmp.cur;
	}
	template<class T>
	int VectIt<T>:: operator != (const VectIt<T>& cmp) const{
		return cur != cmp.cur;
	}
	template<class T>
	class ConstVectIt{
	private:
		const T* cur;
	public:
		ConstVectIt() : cur(nullptr) {}
		ConstVectIt(T* obj) : cur(obj) {}
		const T& operator * () const;
		const T* operator -> () const;
		const T& operator [] (int pos) const;
		ConstVectIt& operator ++();
		ConstVectIt operator ++ (int);
		ConstVectIt operator +(int t) const;
		ConstVectIt operator -(int t) const;
		int operator == (const ConstVectIt& cmp) const;
		int operator != (const ConstVectIt& cmp) const;
	};
	template<class T>
	const T& ConstVectIt<T>:: operator * () const{
		if (!cur){
			throw std::domain_error("Указатель на NULL");
		}
		return *cur;
	}
	template<class T>
	const T* ConstVectIt<T>::operator -> () const{
		return cur;
	}
	template<class T>
	const T& ConstVectIt<T>::operator [] (int pos) const{
		if (!cur){
			throw std::domain_error("Указатель на NULL");
		}
		return *(cur + pos);
	}
	template<class T>
	ConstVectIt<T>& ConstVectIt<T>::operator ++(){
		cur++;
		return(*this);
	}
	template<class T>
	ConstVectIt<T> ConstVectIt<T>::operator ++(int){
		ConstVectIt<T> res(*this);
		cur++;
		return res;
	}
	template<class T>
	int ConstVectIt<T>:: operator == (const ConstVectIt<T>& cmp) const{
		return cur == cmp.cur;
	}
	template<class T>
	int ConstVectIt<T>:: operator != (const ConstVectIt<T>& cmp) const{
		return cur != cmp.cur;
	}
	template<class T>
	ConstVectIt<T> ConstVectIt<T>::operator +(int t) const{
		return ConstVectIt<T>(cur + t);
	}
	template<class T>
	ConstVectIt<T> ConstVectIt<T>::operator -(int t) const{
		return ConstVectIt<T>(cur - t);
	}
	template<class T>
	class vector {
	private:
		int maxSize_; // размер выделенной памяти
		int size_; // текущее количество элементов
		static const int quota_ = 10; // на такой размер увеличивается maxSize_
		T* arr_; // динамический массив
	public:
		vector();
		explicit vector(int num);
		void push_back(const T& value);
		void reserve(int quan);
		void clear();
		int size() const;
		int max_size() const;
		bool empty() const;
		T& operator [] (int pos);
		const T& operator [] (int pos) const;
		vector(const vector&);
		vector& operator = (const vector&);
		friend class VectIt<T>;
		typedef VectIt<T> iterator;
		friend class ConstVectIt<T>;
		typedef ConstVectIt<T> const_iterator;
		iterator begin();
		iterator end();
		const_iterator cbegin() const;
		const_iterator cend() const;
		iterator erase(iterator pos);
		~vector(){ delete[] arr_; }
	};
	template<class T>
	vector<T>::vector(){
		maxSize_ = 0;
		size_ = 0;
		arr_ = nullptr;
	}

	template<class T>
	vector<T>::vector(int num){
		int q = num / quota_ + 1;
		maxSize_ = q*quota_;
		size_ = num;
		arr_ = new T[maxSize_];
		return;
	}

	template<class T>
	void vector<T>::push_back(const T& value){
		if (size_ == 0){
			arr_ = new T[quota_];
			maxSize_ = quota_;
			arr_[size_++] = value;
			return;
		}
		if (size_ < maxSize_){
			arr_[size_++] = value;
		}
		else {
			T* ptr = arr_;
			arr_ = new T[maxSize_ + quota_];
			maxSize_ += quota_;
			for (int i = 0; i < size_; ++i){
				arr_[i] = ptr[i];
			}
			delete[] ptr;
			arr_[size_++] = value;
		}
		return;
	}

	template<class T>
	void vector<T>::reserve(int quan) {
		int q = quan / quota_ + 1;
		maxSize_ = q*quota_;
		size_ = quan;
		arr_ = new T[maxSize_];
		return;
	}

	template<class T>
	void vector<T>::clear(){
		maxSize_ = 0;
		size_ = 0;
		delete[] arr_;
		arr_ = nullptr;
	}
	template<class T>
	int vector<T>::size() const{
		return size_;
	}
	template<class T>
	int vector<T>::max_size() const{
		return maxSize_;
	}
	template<class T>
	bool vector<T>::empty() const{
		return size_ == 0;
	}
	template<class T>
	T& vector<T>::operator [] (int pos){
		if (pos >= size_){
			throw std::out_of_range("Некорректный индекс");
		}
		return arr_[pos];
	}
	template<class T>
	const T& vector<T>::operator [] (int pos) const{
		if (pos >= size_){
			throw std::out_of_range("Некорректный индекс");
		}
		return arr_[pos];
	}
	template<class T>
	typename vector<T>::iterator vector<T>::begin() {
		return vector<T>::iterator(arr_);
	}
	template<class T>
	typename vector<T>::iterator vector<T>::end(){
		return vector<T>::iterator(arr_ + size_);
	}
	template<class T>
	typename vector<T>::const_iterator vector<T>::cbegin() const{
		return vector<T>::const_iterator(arr_);
	}
	template<class T>
	typename vector<T>::const_iterator vector<T>::cend() const{
		return vector<T>::const_iterator(arr_ + size_);
	}
	template<class T>
	typename vector<T>::iterator vector<T>::erase(typename vector<T>::iterator pos){
		vector<T>::iterator prev(pos);
		if ((++pos) == this->end()){
			--size_;
			return pos;
		}
		pos = prev;
		T* mas = &(*pos);
		while (++pos != end()){
			*prev = *pos;
			prev = pos;
		}
		--size_;
		iterator res(mas);
		return res;
	}
	template<class T>
	vector<T>::vector(const vector<T>& obj){
		size_ = obj.size_;
		maxSize_ = obj.maxSize_;
		arr_ = new T[maxSize_];
		for (int i = 0; i<size_; ++i){
			arr_[i] = obj.arr_[i];
		}
	}
	template<class T>
	vector<T>& vector<T>::operator = (const vector<T>& obj){
		if (this != &obj){
			this->clear();
			size_ = obj.size_;
			maxSize_ = obj.maxSize_;
			arr_ = new T[maxSize_];
			for (int i = 0; i<size_; ++i){
				arr_[i] = obj.arr_[i];
			}
		}
		return (*this);
	}
}

#endif // VECTOR_H