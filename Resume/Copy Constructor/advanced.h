// advanced.h
#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>

namespace resume {

	// 1. Copy Constructor in Inheritance
	class Base {
	protected:
		std::string name;
	public:
		Base(std::string n) : name(n) {}
		Base(const Base& other) : name(other.name) {
			std::cout << "[Base] Copy constructor\n";
		}
	};

	class Derived : public Base {
	private:
		int value;
	public:
		Derived(std::string n, int v) : Base(n), value(v) {}
		Derived(const Derived& other) : Base(other), value(other.value) {
			std::cout << "[Derived] Copy constructor\n";
		}
	};

	// 2. Copy Constructor with shared_ptr (shared ownership)
	class SharedResource {
	private:
		std::shared_ptr<std::vector<int>> data;
	public:
		SharedResource() : data(std::make_shared<std::vector<int>>(10, 0)) {}

		SharedResource(const SharedResource& other) : data(other.data) {
			std::cout << "[SharedResource] Shared ownership copy constructor\n";
		}

		void modify(int index, int value) {
			(*data)[index] = value;
		}

		void print() {
			for (int val : *data)
				std::cout << val << ' ';
			std::cout << '\n';
		}
	};

	// 3. Copy Constructor with unique_ptr (prohibited copy)
	class UniqueResource {
	private:
		std::unique_ptr<int> value;
	public:
		UniqueResource(int v) : value(std::make_unique<int>(v)) {}

		UniqueResource(const UniqueResource& other) = delete; // Cannot copy unique_ptr

		UniqueResource(UniqueResource&& other) noexcept : value(std::move(other.value)) {
			std::cout << "[UniqueResource] Move constructor\n";
		}

		void print() const {
			if (value)
				std::cout << "Value: " << *value << '\n';
			else
				std::cout << "Empty\n";
		}
	};

	// 4. Copy Constructor with arrays or containers
	class ContainerCopy {
	private:
		std::vector<std::string> items;
	public:
		ContainerCopy(const std::vector<std::string>& data) : items(data) {}

		ContainerCopy(const ContainerCopy& other) : items(other.items) {
			std::cout << "[ContainerCopy] Copy constructor\n";
		}

		void print() const {
			for (auto& str : items)
				std::cout << str << ", ";
			std::cout << '\n';
		}
	};

	// 5. Deep Copy of dynamically allocated data (manual clone)
	class DeepClone {
	private:
		int* arr;
		size_t size;
	public:
		DeepClone(size_t sz) : size(sz) {
			arr = new int[sz];
			for (size_t i = 0; i < sz; ++i) arr[i] = static_cast<int>(i);
		}

		DeepClone(const DeepClone& other) : size(other.size) {
			arr = new int[size];
			for (size_t i = 0; i < size; ++i)
				arr[i] = other.arr[i];
			std::cout << "[DeepClone] Deep copy constructor\n";
		}

		~DeepClone() { delete[] arr; }

		void print() const {
			for (size_t i = 0; i < size; ++i)
				std::cout << arr[i] << ' ';
			std::cout << '\n';
		}
	};

	// ************** USAGE EXAMPLES **************
	static void _advancedUsage() {
		std::cout << "\n== Inheritance ==\n";
		Derived d1("Ana", 42);
		Derived d2 = d1;

		std::cout << "\n== Shared Resource ==\n";
		SharedResource s1;
		s1.modify(0, 99);
		SharedResource s2 = s1;
		s2.modify(1, 88);
		s1.print();
		s2.print();

		std::cout << "\n== Unique Resource ==\n";
		UniqueResource u1(10);
		// UniqueResource u2 = u1; // Error (copy deleted)
		UniqueResource u3 = std::move(u1);
		u3.print();
		u1.print();

		std::cout << "\n== Container Copy ==\n";
		ContainerCopy cc1({ "one", "two", "three" });
		ContainerCopy cc2 = cc1;
		cc2.print();

		std::cout << "\n== Deep Clone ==\n";
		DeepClone dc1(5);
		DeepClone dc2 = dc1;
		dc1.print();
		dc2.print();
	}

} // resume
