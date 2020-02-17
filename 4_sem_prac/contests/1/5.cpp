int main()
{
    int count;
    std::cin >> count;

    Holder mas[count];
    for (int i = 0; i < count / 2; ++i)
    {
        mas[i].swap(mas[count - i - 1]);
    }
    return 0;
}