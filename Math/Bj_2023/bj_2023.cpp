#include <iostream>
#include <vector>

using namespace std;

bool IsPrime(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

void special_prime(int N, int result)
{
    if (N == 1)
    {
        std::cout << result << std::endl;
    }
    else
    {
        for (size_t i = 0; i < 5; i++)
        {
            int curr_num = result * 10 + 2 * i + 1;
            if (IsPrime(curr_num))
            {
                special_prime(N - 1, curr_num);
            }
        }
    }
}

int main()
{

    int N;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    std::cin >> N;

    int prime_initial[4] = {2, 3, 5, 7};

    for (int i = 0; i < 4; i++)
    {
        int result = prime_initial[i];
        special_prime(N, result);
    }
}