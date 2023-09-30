template<class T>
class LinearList {
public:
	LinearList() = 0;
	~LinearList() = 0;
	virtual int size()const = 0;
	virtual int length()const = 0;
	virtual int search(T& x)const = 0;
	virtual int locate(int i)const = 0;
	virtual bool getData(int i, T& x) = 0;
	virtual void setData(int i, T& x) = 0;
	virtual bool insert(int i, T& x) = 0;
	virtual bool remove(int i, T& x) = 0;
	virtual bool isEmpty()const = 0;
	virtual bool isFull()const = 0;
	virtual void sort() = 0;
	virtual void input() = 0;
	virtual void output() = 0;
	virtual LinearList<T> operator=(LinearList<T>& L) = 0;
};