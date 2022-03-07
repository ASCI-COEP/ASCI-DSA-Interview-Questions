class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for l in matrix:
            if(target in l):
                return True
                break
        else:
            return False