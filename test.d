// Test _d_eh_isExceptionInFlight function.

extern (C) bool _d_eh_isExceptionInFlight();

struct S
{
    ulong line;
    this(ulong line)
    {
        this.line = line;
    }

    ~this()
    {
        assert(_d_eh_isExceptionInFlight());
    }
}

void foo()
{
    try
    {
        S s = S(__LINE__);
        throw new Exception("yo");
    }
    finally
    {
        assert(_d_eh_isExceptionInFlight());
        throw new Exception("chained!");
    }
}

void main()
{
    try
    {
        scope(exit) assert(_d_eh_isExceptionInFlight());
        S s = S(__LINE__);
        foo();
    }
    catch (Exception)
    {
        assert(!_d_eh_isExceptionInFlight());

        try
        {
            scope(exit) throw new Exception("adasd");
            foo();
        }
        catch (Exception)
        {
            assert(!_d_eh_isExceptionInFlight());
        }
    }
    assert(!_d_eh_isExceptionInFlight());
}
