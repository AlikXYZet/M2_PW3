#include <iostream>
#include <vector>

/* Константный forward-итератор должен иметь следующие свойства:
*
* Поддерживает:
* чтение элемента итератора: *it и/или it->v;
* инкремент: ++it и it++;
* сравнение на равенство и неравенство: it == it0, it != it0;
*
* Не поддерживает:
* декремент: --it и it--;
* сравнение с использованием <, <=, >, >=;
* возврат ссылки на элемент с использованием it[i];
* такие операции, как p+=i, p-=i, p-p1.
*/

// Реализация своего Константного forward-итератора 
class cf_it
{
private:
	std::vector<int>* V;
	int index = 0;

public:
	cf_it(std::vector<int>& inV)
	{
		V = &inV;
		index = 0;
	}

	// Чтение
	int operator*() const
	{
		// Вывод ошибки, аналогичной при *V.end()
		_STL_VERIFY(index < V->size(), "(cf_it) can't dereference out of range vector iterator");

		return *(&(V->front()) + index);
	};

	// Пре-инкремент
	cf_it& operator++()
	{
		if (index < (V->size()))
			index++;
		return *this;
	}

	// Пост-инкремент
	cf_it operator++(int)
	{
		auto out = *this;
		++(*this);
		return out;
	}

	// Сравнение на равенство
	bool operator==(const int* inRef) const
	{
		return inRef == (&(V->front()) + index);
	};

	// Сравнение на НЕравенство
	bool operator!=(const int* inRef) const
	{
		return inRef != (&(V->front()) + index);
	};
};


int main()
{
	// Инициализация вектора с последующей записью и воводом
	std::vector<int> V1;

	std::cout << "{ ";
	for (int i = 0; i < 10; i++)
	{
		V1.push_back(i);
		std::cout << V1[i];
		if (i != 9)
			std::cout << ", ";
	}
	std::cout << " }" << std::endl;
	// ----------------------------------------------------------------------


	// Использование const_iterator как "константного forward-итератора"
	std::vector<int>::const_iterator itV1;

	std::cout << "{";
	for (itV1 = V1.begin(); itV1 != V1.end(); ++itV1)
	{
		std::cout << " " << *itV1 << " ";
	}
	std::cout << "}" << std::endl;
	// ----------------------------------------------------------------------


	// Демонстрация операций над const_iterator, недоступных для "константного forward-итератора"
	itV1 = V1.end();

	std::cout << "{";
	do
	{
		itV1--;
		std::cout << " " << *itV1 << " ";
	} while (itV1 > V1.begin());
	std::cout << "}" << std::endl;
	// ----------------------------------------------------------------------


	// Использование своего итератора cf_it без использования итераторов std::vector
	std::cout << "{";
	for (cf_it itV2(V1); itV2 != (&V1.back() + 1); ++itV2)
	{
		std::cout << " " << *itV2 << " ";
	}
	std::cout << "}" << std::endl;
	// ----------------------------------------------------------------------

	return 0;
}