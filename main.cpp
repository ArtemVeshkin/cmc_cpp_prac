#include <cstdio>

class FileWrapper
{
	FILE *f_ = nullptr;
	int* count_ = nullptr;

public:
	FileWrapper(const char* filename) : f_(fopen(filename, "w")), count_(new int{1}) {}

	FileWrapper(const FileWrapper& parent) : f_(parent.f_), count_(parent.count_)
	{
		++(*count_);
	}

	FileWrapper(FileWrapper&& parent) : f_(parent.f_), count_(parent.count_)
	{
		parent.count_ = new int{1};
		parent.f_ = nullptr;
	}

	~FileWrapper()
	{
		if (*count_ == 1)
		{
			fclose(f_);
			delete count_;
		} else {
			--(*count_);
		}
	}

	FileWrapper operator=(const FileWrapper& parent)
	{
		f_ = parent.f_;
		count_ = parent.count_;
		++(*count_);
		return *this;
	}
	
	FileWrapper operator=(FileWrapper&& parent)
	{
		f_ = parent.f_;
		count_ = parent.count_;
		parent.count_ = new int{1};
		parent.f_ = nullptr;
		return *this;
	}

	friend FileWrapper& operator<<(FileWrapper& out, const char& msg);
};

FileWrapper& operator<<(FileWrapper& out, const char& msg)
{
	fprintf(out.f_, "%c", msg);
	return out;
}