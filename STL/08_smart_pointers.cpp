

#include <iostream>
#include <vector>
#include <string>
#include <memory>

void check_smart_pointers(void)
{
	//initialization
	std::shared_ptr<std::string> ptrH(new std::string("Hello"));
	std::shared_ptr<std::string> ptrW(new std::string("World"));

	std::vector<std::shared_ptr<std::string>> vec;
	vec.push_back(ptrH);
	vec.push_back(ptrW);

	for(auto ptr : vec) 
		std::cout<<"string - "<<*ptr<<std::endl;

	//deleting policy
	std::shared_ptr<std::string> ptrN(new std::string("Titan"), 
										[](std::string *p) {
											std::cout<<"delete -"<<*p<<std::endl;
											delete p;
										});

	std::shared_ptr<std::string> ptrP(new std::string[10],
										[](std::string *p) {
											std::cout<<"deleting -"<<*p<<std::endl;
											delete[] p;
										});

	std::shared_ptr<int> ptrNum(new int[10],
									[](int *p) {
										std::cout<<"deleting"<<std::endl;
										delete[] p;
									});

	std::shared_ptr<int> ptrNum2(new int[10], std::default_delete<int []>());

	std::cout<<std::endl;

	return;
}