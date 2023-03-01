// CPP Program to demonstrate Big Integer data type
#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/algorithm/string.hpp>
#include<string>
#include <boost/algorithm/cxx11/none_of.hpp> //for none_of_equal
#include <boost/algorithm/cxx11/one_of.hpp> // for one_of_equal
#include <boost/algorithm/cxx11/all_of.hpp> // for all_of  & all_of_equal
#include <boost/algorithm/cxx11/any_of.hpp> // for any_of_equal
#include <boost/algorithm/cxx11/is_sorted.hpp>

boost::multiprecision::int128_t boost_product(long long A, long long B)
{
	boost::multiprecision::int128_t ans = (boost::multiprecision::int128_t)A * B;
	return ans;
}

boost::multiprecision::cpp_int boost_factorial(int num)
{
	boost::multiprecision::cpp_int fact = 1;
	for (int i = num; i > 1; --i)
		fact *= i;
	return fact;
}

template <typename T> inline T area_of_a_circle(T r)
{
	// pi represent predefined constant having value
	// 3.1415926535897932384...
	using boost::math::constants::pi;
	return pi<T>() * r * r;
}

// function to generate first n
// fibonacci numbers
void fib(unsigned int n)
{
	// seed values
	// 0th and 1st number of the
	// series are 0 and 1
	boost::multiprecision::cpp_int a = 0;
	boost::multiprecision::cpp_int b = 1;
	std::cout << a << "  ";
	std::cout << b << "  ";

	for (unsigned int i = 2; i < n; ++i)
	{
		const boost::multiprecision::cpp_int c = a + b;
		std::cout << c << "  ";
		a = b;
		b = c;
	}
}

boost::multiprecision::cpp_int Factorial(int number)
{
	boost::multiprecision::cpp_int num = 1;
	for (int i = 1; i <= number; i++)
		num = num * i;
	return num;
}

bool isOdd(int i)
{
	return i % 2 == 1;
}

bool allLessThanSeven(int i)
{
	return i < 7;
}


int main()
{
	////................1. Big Integer Data Type
	////int128_t
	////int256_t
	////int512_t
	////int1024_t
	std::cout << "1. Big Integer Data Type \n";
	long long first = 98745636214564698;
	long long second = 7459874565236544789;
	std::cout << "Product of " << first << " * " << second
		<< " = \n"
		<< boost_product(first, second);

	////...........2. Arbitrary Precision Data Type
	std::cout << "\n\n2. Arbitrary Precision Data Type \n";
	////cpp_int:  It automatically converts the desired precision at the Run-time.  if we are not sure about precision 

	int num = 30;
	std::cout << "Factorial of " << num << " = "
		<< boost_factorial(num);


	////.................3. Multiprecision Float
	std::cout << "\n\n3. Multiprecision Float \n";
	////cpp_float_50 and cpp_dec_float_100

	float radius_f = 123.0 / 100;
	float area_f = area_of_a_circle(radius_f);

	double radius_d = 123.0 / 100;
	double area_d = area_of_a_circle(radius_d);

	boost::multiprecision::cpp_dec_float_50 r_mp = 123.0 / 100;
	boost::multiprecision::cpp_dec_float_50 area_mp = area_of_a_circle(r_mp);

	// numeric_limits::digits10 represent the number
	// of decimal digits that can be held of particular
	// data type without any loss.  
	////it is a function of std

	// Area by using float data type
	std::cout << "Float: "
		<< std::setprecision(std::numeric_limits<float>::digits10)
		<< area_f << std::endl;

	// Area by using double data type
	std::cout << "Double: "
		<< std::setprecision(std::numeric_limits<double>::digits10)
		<< area_d << std::endl;

	// Area by using Boost Multiprecision
	std::cout << "Boost Multiprecision: "
		<< std::setprecision(
			std::numeric_limits<boost::multiprecision::cpp_dec_float_50>::digits10)
		<< area_mp << std::endl;

	////.................Boost String Algorithms Library
	std::cout << "\n\n\n........... Boost String Algorithms Library .........";

	////.................4. to_upper() 
	std::cout << "\n\n4. boost::algorithm::to_upper() \n";

	std::string str("Hello");
	std::string upper_s;
	std::string lower_s;

	std::cout << "Actual string: "
		<< str << std::endl;

	boost::algorithm::to_upper(str);
	std::cout << "String converted to uppercase: "
		<< str << std::endl;
	
	////.................5. to_lower() 
	std::cout << "\n\n5. boost::algorithm::to_lower() \n";

	boost::algorithm::to_lower(str);
	std::cout << "String converted to lowercase: "
		<< str << std::endl;

	////.................6. to_upper_copy() 
	std::cout << "\n\n6. boost::algorithm::to_upper_copy() \n";

	str = "Hello";
	upper_s = boost::algorithm::to_upper_copy(str);


	std::cout << "Converted Uppercase string: "
		<< upper_s << std::endl;

	std::cout << "\nActual string: "
		<< str << std::endl;

	////.................7. to_lower() 
	std::cout << "\n\n7. boost::algorithm::to_lower_copy() \n";

	lower_s = boost::algorithm::to_lower_copy(str);

	std::cout << "Converted Lowercase string: "
		<< lower_s << std::endl;
	



	////.................To remove characters from a string.........
	std::cout << "\n\n.......To remove character(s) from a string........ \n";

	std::string s = "geeksforgeeks";

	std::cout << "\nActual string: "
		<< s << std::endl;

	////.................8. erase_first_copy
	std::cout << "\n8. erase_first_copy of \"g\" : ";

	std::cout << boost::algorithm::erase_first_copy(s, "g") << '\n';

	////.................9. erase_nth_copy
	std::cout << "\n\n9. erase_nth_copy of \"g\" : ";

	std::cout << boost::algorithm::erase_nth_copy(s, "g", 0) << '\n';
	
	std::cout << "\nActual string : "
		<< s << " (untouched) " << std::endl;

	////.................10. erase_last_copy
	std::cout << "\n\n10. erase_last_copy of \"g\" : \n";

	std::cout << boost::algorithm::erase_last_copy(s, "g") << '\n';

	////.................11. erase_all_copy
	std::cout << "\n\n11. erase_all_copy of \"g\" : \n";

	std::cout << boost::algorithm::erase_all_copy(s, "g") << '\n';

	////.................12. erase_head_copy
	std::cout << "\n\n12. erase_head_copy  (actual string not changed) \n";

	std::cout << boost::algorithm::erase_head_copy(s, 5) << '\n';

	std::cout << "\nActual string : "
		<< s << " (untouched) " << std::endl;

	////.................13. erase_tail_copy
	std::cout << "\n\n13. erase_tail_copy\n";

	std::cout << boost::algorithm::erase_tail_copy(s, 3) << '\n';




	////To replace characters from a string
	////Boost.StringAlgorithms provides several functions you can use to replace individual characters from a string.

	std::cout << "\n\n.......To replace characters from a string .....\n";


	std::string str1 = "geeks_for_geeks";

	std::cout << "\nActual string : "
		<< str1;

	////.................14. replace_first_copy
	std::cout << "\n\n14. replace_first_copy of \"_\" with \"-\" \n";

	std::cout
		<< boost::replace_first_copy(str1, "_", "-")
		<< '\n';
	
	////.................15. replace_last_copy
	std::cout << "\n\n15. replace_last_copy of \"_\" with \"-\" \n";
	std::cout
		<< boost::replace_last_copy(str1, "_", "-")
		<< '\n';
	
	////.................16. replace_all_copy
	std::cout << "\n\n16. replace_all_copy of \"_\" with \"-\" \n";
	std::cout
		<< boost::replace_all_copy(str1, "_", "-")
		<< '\n';


	////.................16. Generating large Fibonacci numbers using boost library
	std::cout << "\n\n.........16. Generating large Fibonacci numbers using boost library.........\n";


	unsigned int n = 40;

	// function calling
	fib(n);

	////.........17. Factorial of Large Number Using boost multiprecision Library
	std::cout << "\n\n\n.........17. Factorial of Large Number Using boost multiprecision Library.......\n";

	int number = 50;
	boost::multiprecision::cpp_int fact = Factorial(number);
	std::cout << fact << std::endl;


	/////........18. boost::algorithm::none_of_equal
	std::cout << "\n\n\n....18. boost::algorithm::none_of_equal()....\n";

	std::vector<int> c(5, 1);
	std::cout << "c [1, 1, 1, 1, 1]\n";

	// Run the function
	bool ans
		= boost::algorithm::none_of_equal(c, 1);

	// Condition to check
	if (ans == 1)
		std::cout << "all not equal to 1";
	else
		std::cout << "all equals to 1";


	/////........19. boost::algorithm::one_of_equal
	std::cout << "\n\n\n....19. boost::algorithm::one_of_equal()....\n";

	int c1[] = { 1, 2, 3, 1 };
	bool ans1 = boost::algorithm::one_of_equal(c1, 1);

	// Condition to check
	if (ans1 == 1)
		std::cout << "exactly one element is 1";
	else
		std::cout << "exactly one element is not 1";

	 ans1 = boost::algorithm::one_of_equal(c1, c1 + 2, 1);

	// Condition to check
	if (ans1 == 1)
		std::cout << "\n\nexactly one element is 1";
	else
		std::cout << "\nexactly one element is not 1";


	/////........20. boost::algorithm::all_of
	std::cout << "\n\n\n....20. boost::algorithm::all_of()....\n";


	ans = boost::algorithm::all_of(c, isOdd);

	// Condition to check
	if (ans == 1)
		std::cout << "\nAll elements are odd in c[1,1,1,1,1]";
	else
		std::cout << "\nAll elements are not odd in c[1,1,1,1,1]";

	ans = boost::algorithm::all_of(c1, isOdd);
	//ans = boost::algorithm::all_of(c1, c1 + 1, isOdd);

	// Condition to check
	if (ans == 1)
		std::cout << "\nAll elements are odd in c1[] = { 1, 2, 3, 1 }";
	else
		std::cout << "\nAll elements are not odd in c1[] = { 1, 2, 3, 1 }";

	int c2[] = { 1, 2, 3, 6, 6 };
	//int c2[] = { 1, 2, 3, 7, 6 };


	ans = boost::algorithm::all_of(c2, c2 + 4, allLessThanSeven);

	// Condition to check
	if (ans == 1)
		std::cout << "\nAll elements in c1 are less than 7";
	else
		std::cout << "\nAll elements in c1 are not less than 7";


	/////........21. boost::algorithm::all_of_equal 
	std::cout << "\n\n\n....21. boost::algorithm::all_of_equal()....\n";

	ans = boost::algorithm::all_of_equal(c, 1);

	// Condition to check
	if (ans == 1)
		std::cout << "All elements are 1";
	else
		std::cout << "All elements are not 1";


	/////........22. boost::algorithm::one_of :: exactly one of the element share the property given
	std::cout << "\n\n\n....22. boost::algorithm::one_of()....\n";

	ans = boost::algorithm::one_of(c, isOdd);

	// Condition to check
	if (ans == 1)
		std::cout << "Exactly one element is odd";
	else
		std::cout << "Exactly one element is not odd";
	
	
	/////........23. boost::algorithm::any_of_equal ::  returns true if the any of the elements are same in the sequence to the value passed.
	std::cout << "\n\n\n....23. boost::algorithm::any_of_equal()....\n";

	//ans = boost::algorithm::any_of_equal(c1, 1);
	ans = boost::algorithm::any_of_equal(c1, 4);

	// Condition to check
	if (ans == 1)
		std::cout << "at least one elements is 4";
	else
		std::cout << "not any elements is 4";
	
	/////........24. boost::algorithm::is_sorted
	std::cout << "\n\n\n....24. boost::algorithm::is_sorted()....\n";

	//ans = boost::algorithm::is_sorted(c1);
	ans = boost::algorithm::is_sorted(c2);

	// Condition to check
	if (ans == 1)
		std::cout << "c2 is sorted";
	else
		std::cout << "c2 is not sorted";
	





	std::cout << "\n\n";

	return 0;
}
