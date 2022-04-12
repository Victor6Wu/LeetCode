#pragma once

template<typename T>
class SmartPointer {
public:
	SmartPointer(T* ptr) :rp(new T(ptr)) { }

	SmartPointer(const SmartPointerr& sp) :rp(sp.rp) { ++rp->count; }

	SmartPointer& operator=(const SmartPointer& rhs) {
		++rhs.rp->count;
		if (--rp->count == 0)
			delete rp;
		rp = rhs.rp;
		return *this;
	}

	~SmartPointer() {
		if (--rp->count == 0)
			delete rp;
		else
			cout << "还有" << rp->count << "个指针指向基础对象" << endl;
	}

private:
	T* rp;
};               

