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
    for (; created < rows; created++)
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
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      mtx[i][j] = init;
    }
  }
}

void input(int **mtx, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      std::cin >> mtx[i][j];
    }
  }
}

void output(int **mtx, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    std::cout << mtx[i][0];
    for (size_t j = 1; j < cols; ++j)
    {
      std::cout << " " << mtx[i][j];
    }
    std::cout << "\n";
  }
}

int main() 
{
  size_t rows = 5, cols = 5;
  std::cin >> rows >> cols;
  if (!std::cin)
  {
    std::cerr << "Bad input\n";
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
  input(mtx, rows, cols);
  if (!std::cin)
  {
    std::cerr << "Bad input!\n";
    destroy_matrix(mtx, rows);
    return 2;
  }
  output(mtx, rows, cols);
  destroy_matrix(mtx, rows);
}
