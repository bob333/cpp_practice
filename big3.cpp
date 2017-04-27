#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
std::string NumberToString ( T Number )
{
  std::ostringstream ss;
  ss << hex<<Number;
  return ss.str();
}

class Emp
{
public:
  Emp()
  {
    cout<<hex;
    cout<<"Constructor Emp: "<<getObjectAddress()<<endl;
  }

  Emp(const Emp& e)
  {
    cout<<"Copy Constructor"<<getObjectAddress()<<endl;
  }

  Emp& operator=(const Emp& e)
  {
    cout<<"Assignment Operator"<<getObjectAddress()<<endl;
    return *this;
  }

  Emp& operator++()
  {
    cout<<"preincrement operator "<<getObjectAddress()<<endl;
    return *this;
  }

  string getObjectAddress()
  {
    return "0x" + NumberToString(reinterpret_cast<unsigned long long int>(this));
  }

private:
  unsigned long long int id;
};

int main(int argc, char **argv)
{
  Emp a;
  Emp b;
  b = ++a;
}
