#include <vector>
#include <algorithm>
#include <exception>
#include <string>
#include <iostream>
#include <cassert>
#include <stdexcept>


class KeyNotFoundException : public std::exception {
public:
	explicit KeyNotFoundException(const std::string& key)
		: m_Message("Key not found: " + key) {}

	const char* what() const noexcept override {
		return m_Message.c_str();
	}

private:
	std::string m_Message;
};


template <typename K, typename V>
class VectorMap {
private:
	std::vector<K> m_Keys = std::vector<K>();;
	std::vector<V> m_Values = std::vector<V>();

	__int64 find_index_of_key(K key) {
		auto it = std::find(m_Keys.begin(), m_Keys.end(), key);

		if (it == m_Keys.end()) {
			return -1;
		}

		return std::distance(m_Keys.begin(), it);
	}

	std::string key_to_string(const K& key) const {
		if constexpr (std::is_convertible<K, std::string>::value) {
			return static_cast<std::string>(key);
		}
		else {
			return std::to_string(key);
		}
	}
	
public:
	V& operator[](const K& key) {
		__int64 key_index = find_index_of_key(key);

		if (key_index == -1) {
			m_Keys.emplace_back(key);

			m_Values.emplace_back(V{});

			return m_Values.back();
		}

		return m_Values.at(key_index);
	}

	void insert(K key, V val) {
		__int64 index_of_key = find_index_of_key(key);
		
		if (index_of_key == -1) {
			m_Keys.emplace_back(key);
			m_Values.emplace_back(val);
			return;
		}

		m_Values[index_of_key] = val;
	}

	V& at(K key) {
		__int64 index_of_key = find_index_of_key(key);

		if (index_of_key == -1) {
			std::string converted_key = key_to_string(key);

			throw KeyNotFoundException(converted_key);

		}

		return m_Values[index_of_key];
	}
};

void test_basic_functionality() {
	VectorMap<int, std::string> map;
	map.insert(1, "one");
	map.insert(2, "two");

	assert(map[1] == "one");
	assert(map[2] == "two");

	map.insert(1, "one_overwritten");
	assert(map[1] == "one_overwritten");

	map.insert(4, "four");

	assert(map.at(4) == "four");

	assert(map[34] == "");

	std::cout << "test_basic_functionality passed!" << std::endl;
}

void test_exception_handling() {
	VectorMap<int, std::string> map;
	map.insert(1, "one");

	try {
		map.at(2);
		assert(false); // Should not reach here
	}
	catch (const KeyNotFoundException& e) {
		bool error_contains_some_text = std::string(e.what()).length() > 0;

		assert(error_contains_some_text);
	}

	VectorMap<std::string, int> map1;

	map1.insert("test", 1);

	try {
		map1.at("another_key");
		assert(false);
	}
	catch (const KeyNotFoundException& e) {
		bool error_contains_some_text = std::string(e.what()).length() > 0;

		assert(error_contains_some_text);
	}

	std::cout << "test_exception_handling passed!" << std::endl;
}

void test_different_key_value_types() {
	VectorMap<char, int> map;
	map.insert('a', 1);
	map.insert('b', 2);

	assert(map['a'] == 1);
	assert(map.at('b') == 2);

	VectorMap<bool, float> map1;
	map1.insert(false, 0.3f);
	map1.insert(true, 0.5f);

	assert(map1[false] == 0.3f);
	assert(map1.at(true) == 0.5f);

	VectorMap<float, std::string> map2;
	map2.insert(0.3f, "test");
	map2.insert(0.5f, "another_test");

	assert(map2[0.3f] == "test");
	assert(map2.at(0.5f) == "another_test");

	std::cout << "test_different_key_value_types passed!" << std::endl;
}


int main() {
	test_basic_functionality();
	test_exception_handling();
	test_different_key_value_types();

	std::cout << "All tests passed!" << std::endl;
	return 0;
}
