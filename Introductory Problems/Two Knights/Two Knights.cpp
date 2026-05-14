
#include <iostream>

long saltosPosiblesExterno(long k) {
	switch (k)
	{
	case 1:
	case 2:
		return 0;
	case 3:
		return 16;
	default:
		return (16 * (k - 4) + 32);
	}
}

long saltosPosiblesInterno(long k) {
	switch (k)
	{
	case 1:
	case 2:
	case 3:
		return 0;
	default:
		return (24 * (k - 4) + 16);
	}
}

long saltosPosiblesCentro(long k) {
	switch (k)
	{
	case 1:
	case 2:
	case 3:
		return 0;
	default:
		return ((k-4) * (k-4) * 8);
	}
}

long saltosPosibles(long k) {
	return saltosPosiblesExterno(k) + saltosPosiblesInterno(k) + saltosPosiblesCentro(k);
}

long casillasNoAtacadas(long k) {
	return (k * k) * ((k * k) - 1) - saltosPosibles(k);
}

long combinacionesPosibles(long k) {
	return casillasNoAtacadas(k) / 2;
}

int main()
{
	long k;
	std::cin >> k;

	for (int i = 1; i <= k; i++) {
		//std::cout << "k = " << i << ": ";
		//std::cout << saltosPosiblesExterno(i) << " ";
		//std::cout << saltosPosiblesInterno(i) << " ";
		//std::cout << saltosPosiblesCentro(i) << " ";
		//std::cout << saltosPosibles(i) << " ";
		//std::cout << casillasNoAtacadas(i) << " ";
		std::cout << combinacionesPosibles(i) << "\n";
	}
    
}
