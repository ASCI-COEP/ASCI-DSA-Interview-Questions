
import numpy as np


def randomQueens(matrix, n):
    for k in range(n):
        i = np.random.randint(0, n - 1)
        j = np.random.randint(0, n - 1)
        if matrix[i][j] == 1:
            k -= 1
        else:
            matrix[i][j] = 1


def LineCountQueens(matrix, line):
    return np.count_nonzero(matrix[line])


def ColumnCountQueens(matrix, n, col):
    num = 0
    for j in range(n):
        num += matrix[j][col]

    return num


def Diag1CountQueen(matrix, n, line, col):
    num = 0
    for i in range(n):
        c = i + col - line
        if (c >= 0 and c < n):
            num += matrix[i][c]
    return num


def Diag2CountQueen(matrix, n, line, col):
    num = 0
    for i in range(n):
        c = (n - 1 - i) - (n - 1 - col) + line
        if (c >= 0 and c < n):
            num += matrix[i][c]
    return num


def validQueen(matrix, n, line, col):
    return (LineCountQueens(matrix, line) == 0
            and ColumnCountQueens(matrix, n, col) == 0
            and Diag1CountQueen(matrix, n, line, col) == 0
            and Diag2CountQueen(matrix, n, line, col) == 0)


def nQueens(n):
    matrix = np.array([[0 for i in range(n)] for j in range(n)])
    queensColumns = [0 for i in range(n)]
    solutions = []
    
    i = 0
    while i <= n:
        if i == n:
            solutions.append([(x + 1) for x in queensColumns])
            i -= 1
            matrix[i][queensColumns[i]] = 0
            queensColumns[i] += 1
        elif i < 0:
            return solutions
        
        if queensColumns[i] == n:
            queensColumns[i] = 0
            i -= 1
            matrix[i][queensColumns[i]] = 0
            queensColumns[i] += 1
        elif validQueen(matrix, n, i, queensColumns[i]):
            matrix[i][queensColumns[i]] = 1
            i += 1
        else:
            queensColumns[i] += 1
    
    return solutions
    

class Solution:
    def nQueen(self, n):
        return nQueens(n)

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        
        ob = Solution()
        ans = ob.nQueen(n)
        if(len(ans) == 0):
            print("-1")
        else:
            for i in range(len(ans)):
                print("[",end="")
                for j in range(len(ans[i])):
                    print(ans[i][j],end = " ")
                print("]",end = " ")
            print()
                
# } Driver Code Ends