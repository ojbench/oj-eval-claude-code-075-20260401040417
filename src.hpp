#include <algorithm>
#include <cstring>
#include <vector>

class str
{
private:
	char *data;
	size_t length;

	void init_from_cstr(const char *s) {
		if (s == nullptr) {
			length = 0;
			data = new char[1];
			data[0] = '\0';
		} else {
			length = strlen(s);
			data = new char[length + 1];
			strcpy(data, s);
		}
	}

public:
	// Default constructor - empty string
	str() : data(nullptr), length(0) {
		data = new char[1];
		data[0] = '\0';
	}

	// Constructor from char
	str(const char &c) : length(1) {
		data = new char[2];
		data[0] = c;
		data[1] = '\0';
	}

	// Constructor from char* rvalue reference
	str(const char *&& s_) {
		init_from_cstr(s_);
	}

	// Assignment operator from char* rvalue reference
	str &operator=(const char *&& s_) {
		if (data != s_) {
			delete[] data;
			init_from_cstr(s_);
		}
		return *this;
	}

	// Copy constructor
	str(const str &other) : length(other.length) {
		data = new char[length + 1];
		strcpy(data, other.data);
	}

	// Copy assignment operator
	str &operator=(const str &other) {
		if (this != &other) {
			delete[] data;
			length = other.length;
			data = new char[length + 1];
			strcpy(data, other.data);
		}
		return *this;
	}

	// Array subscript operator
	char &operator[](size_t pos) {
		return data[pos];
	}

	// Get length
	size_t len() const {
		return length;
	}

	// Join function - concatenates strings with separator
	str join(const std::vector<str> &strs) const {
		if (strs.empty()) {
			return str();
		}

		// Calculate total length needed
		size_t total_length = 0;
		for (size_t i = 0; i < strs.size(); i++) {
			total_length += strs[i].length;
			if (i < strs.size() - 1) {
				total_length += length; // separator length
			}
		}

		// Create result string
		str result;
		delete[] result.data;
		result.length = total_length;
		result.data = new char[total_length + 1];

		// Build result
		size_t pos = 0;
		for (size_t i = 0; i < strs.size(); i++) {
			strcpy(result.data + pos, strs[i].data);
			pos += strs[i].length;
			if (i < strs.size() - 1) {
				strcpy(result.data + pos, data);
				pos += length;
			}
		}
		result.data[total_length] = '\0';

		return result;
	}

	// Slice function - extract substring [l, r)
	str slice(size_t l, size_t r) const {
		if (l >= length || r > length || l >= r) {
			return str();
		}

		str result;
		delete[] result.data;
		result.length = r - l;
		result.data = new char[result.length + 1];

		for (size_t i = 0; i < result.length; i++) {
			result.data[i] = data[l + i];
		}
		result.data[result.length] = '\0';

		return result;
	}

	// Destructor
	~str() {
		delete[] data;
	}
};
