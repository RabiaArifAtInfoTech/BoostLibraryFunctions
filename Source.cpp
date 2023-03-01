// CPP Program to demonstrate Big Integer data type
#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
#include <boost/math/constants/constants.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/algorithm/string.hpp>
#include<string>


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
	///it is function of std

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
	std::cout << "\n\n........ Boost String Algorithms Library .....";

	////.................4. to_upper() 
	std::cout << "\n\n4. boost::algorithm::to_upper() \n";

	std::string str("Hello");
	std::string upper_s;
	std::string lower_s;

	std::cout << "Actual string: "
		<< str << std::endl;

	boost::algorithm::to_upper(str);
	std::cout << "Actual string converted to uppercase: "
		<< str << std::endl;
	
	////.................5. to_lower() 
	std::cout << "\n\n5. boost::algorithm::to_lower() \n";

	boost::algorithm::to_lower(str);
	std::cout << "Actual string converted to lowercase: "
		<< str << std::endl;

	////.................6. to_upper_copy() 
	std::cout << "\n\n6. boost::algorithm::to_upper_copy() \n";

	str = "Hello";
	upper_s = boost::algorithm::to_upper_copy(str);


	std::cout << "Converted Uppercase string: "
		<< upper_s << std::endl;

	////.................7. to_lower() 
	std::cout << "\n\n7. boost::algorithm::to_lower_copy() \n";

	lower_s = boost::algorithm::to_lower_copy(str);

	std::cout << "Converted Lowercase string: "
		<< lower_s << std::endl;

	////.................To remove characters from a string.........
	std::cout << "\n\nTo remove characters from a string \n";

	////.................8. erase_first_copy
	std::cout << "\n\n8. erase_first_copy of \"g\" \n";

	std::string s = "geeksforgeeks";
	std::cout << boost::algorithm::erase_first_copy(s, "g") << '\n';

	////.................9. erase_nth_copy
	std::cout << "\n\n9. erase_nth_copy\n";

	std::cout << boost::algorithm::erase_nth_copy(s, "g", 0) << '\n';
	
	////.................10. erase_last_copy
	std::cout << "\n\n10. erase_last_copy\n";

	std::cout << boost::algorithm::erase_last_copy(s, "g") << '\n';

	////.................11. erase_all_copy
	std::cout << "\n\n11. erase_all_copy\n";

	std::cout << boost::algorithm::erase_all_copy(s, "g") << '\n';

	////.................12. erase_head_copy
	std::cout << "\n\n12. erase_head_copy\n";

	std::cout << boost::algorithm::erase_head_copy(s, 5) << '\n';

	////.................13. erase_tail_copy
	std::cout << "\n\n13. erase_tail_copy\n";

	std::cout << boost::algorithm::erase_tail_copy(s, 1) << '\n';

	std::cout << "\n\n";

	return 0;
}
