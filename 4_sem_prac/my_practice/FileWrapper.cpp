#include <cstdio>

class FileWrapper
{
	FILE *f_;

public:
	FileWrapper(const char* filename)
	{
		f_ = std::fopen(filename, "w");
	}

	~FileWrapper()
	{
		fclose(f_);
	}

	FILE* get()
	{
		return f_;
	}

	friend FileWrapper& operator<<(FileWrapper& out, const char& msg);
};

FileWrapper& operator<<(FileWrapper& out, const char& msg)
{
	fprintf(out.get(), "%c", msg);
	return out;
}