#include <iostream>

void destroy_matrix(int** mtx, size_t created)
{
    for (size_t i = 0; i < created; i++)
    {
        delete[] mtx[i];
    }
    delete[] mtx;
}

int** create_matrix(size_t rows, size_t cols)
{
    int **mtx = new int *[rows];
    size_t created = 0;
    try
    {
        for (; created < rows; created++) // for (size_t i = 0; i < rows; i++)
        {
            mtx[created] = new int[cols];
        }
    }
    catch (const std::bad_alloc &e)
    {
        destroy_matrix(mtx, created);
        throw;
    }
    return mtx;
}

void costruct(int **mtx, int init, size_t rows, size_t cols)
{
    for (int i = 0; i < rows; ++i)
	{
	    for (int j = 0; j < cols; ++j)
	    {
	        mtx[i][j] = init;
	    }
	}
}

int main() 
{
    size_t rows = 5, cols = 5;
    std::cin >> rows >> cols;
    
    if (std::cin.bad())
	{
	    std::cerr << "Internal stream error!\n";
        return 2;
	}
	else if (std::cin.eof())
	{
	    std::cerr << "Unexpected eof!\n";
	    return 2;
	}
	else if (std::cin.fail())
	{
	    std::cerr << "Unexpected input!\n";
	    return 2;
	}
	   
	int **mtx = nullptr;
	try
	{
	    mtx = create_matrix(rows, cols);
	}
	catch (const std::bad_alloc & e)
	{
	    std::cerr << e.what() << "\n";
	    return 1;
	}
	costruct(mtx, 1, rows, cols);
	for (int i = 0; i < rows; ++i)
	{
	    for (int j = 0; j < cols; ++j)
	    {
	        std::cin >> mtx[i][j];
	    }
	    if (std::cin.bad())
	    {
	        std::cerr << "Internal stream error!\n";
	        return 2;
	    }
	    else if (std::cin.eof())
	    {
	        if (i != rows - 1)
	        {
	            std::cerr << "Unexpected eof!\n";
	            return 2;
	        }
	    }
	    else if (std::cin.fail())
	    {
	        std::cerr << "Unexpected input!\n";
	        return 2;
	   }
	}
	destroy_matrix(mtx, rows);
}
