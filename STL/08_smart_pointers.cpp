

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>

class DeleteFile {
private:
	std::string fname;
public:
	DeleteFile(const std::string &fn):fname(fn) { }
	void operator ()(std::ofstream *fp) {
		fp->close();
		std::remove(fname.c_str());
	}
};

void check_smart_pointers(void)
{
//creation & destruction
	std::shared_ptr<std::string> ptrS;
	//ptrS = new std::string("string");  --> this throws error
	ptrS.reset(new std::string("string"));
	//another way to initialize
	std::shared_ptr<std::string> ptrH(new std::string("Hello"));										
	std::shared_ptr<std::string> ptrW(new std::string("World"));

	std::vector<std::shared_ptr<std::string>> vec;
	vec.push_back(ptrH);
	vec.push_back(ptrW);

	for(auto ptr : vec) 
		std::cout<<"string - "<<*ptr<<std::endl;

	//owner count
	std::cout<<"countH - "<<vec[0].use_count()<<std::endl;
	std::cout<<"countW - "<<vec[1].use_count()<<std::endl;

	//clear vector
	vec.clear();	

//deleting policy 
	try {
	//by default delete is called if no policy defined
	std::shared_ptr<std::string> ptrN(new std::string("Titan"), 
										[](std::string *p) {
										std::cout<<"delete -"<<*p<<std::endl;
										delete p;
									});
	//case of array allocation of string
	std::shared_ptr<std::string> ptrP(new std::string[10],
										[](std::string *p) {
										std::cout<<"deleting array - string"<<*p<<std::endl;
										delete[] p;
									});
	//case of array allocation of int's
	std::shared_ptr<int> ptrNum(new int[10],
								[](int *p) {
								std::cout<<"deleting array - int"<<std::endl;
								delete[] p;
								});	
	//alternative way
	std::shared_ptr<int> ptrNum2(new int[10], std::default_delete<int []>());

	//extending deleting policy to other actions
	std::shared_ptr<std::ofstream> fp(new std::ofstream("tmp.txt"), 
										DeleteFile("tmp.txt"));
	} 
	catch (const std::exception &e) 
	{
		std::cerr << "exception - " <<e.what()<<std::endl;
	}

//pointer arithmetic
	std::shared_ptr<int> pSp(new int(10));
	std::cout<<"val1 - "<<*pSp<<std::endl;
	pSp.get()[0] = 20; pSp.get()[0] += 100;
	std::cout<<"val2 - "<<*pSp<<std::endl;

	std::cout<<std::endl;

	
	return;
}
