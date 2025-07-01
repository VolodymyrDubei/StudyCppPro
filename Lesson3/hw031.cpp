#include<iostream>
#include<string>
#include<cstdio>

class FileManager
{
  private:
    std::FILE* file;

  public:
    explicit FileManager(const char* filename) : file(nullptr)
    {
      file = std::fopen(filename, "w");
      if (!file) 
        {
          throw std::runtime_error(std::string("Failed to open file ") + filename + "!\n");
        }
    }

    ~FileManager()
    {
       if (file) {
           std::fclose(file);
           std::cout << "File closed automatically!\n";
       }
    }

   // Функція запису в файл
  void write(const std::string& text)
  {
    if (!file) 
        {
          throw std::runtime_error("Failed to open file!\n");
        }

    std::fprintf(file, "%s\n", text.c_str());
  }
};


int main()
{
  try
  {
    FileManager document("output.txt");

    document.write("Hello, world!");
    document.write("Це тестовий запис у файл.");
        
    std::cout << "Запис успішно завершено." << std::endl;
  }
  catch (const std::exception& ex)
  {
    std::cerr << "Error: " << ex.what() << std::endl;
  }
    
  return 0;
}








