template <typename Container, typename F>
Container myfilter(const Container& a, F func)
{
    Container result{};
    for (auto elem : a)
    {
        if (func(elem))
        {
            result.insert(result.end(), elem);
        }
    }
    return result;
}