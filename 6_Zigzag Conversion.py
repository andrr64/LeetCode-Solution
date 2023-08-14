class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        listRow : list = [[] for i in range(numRows)]
        result : str = ""

        goUp = False
        index = 0

        for char in s:
            listRow[index].append(char)
            if goUp:
                index -= 1
                if index == 0:
                    goUp = False
            else:
                index += 1
                if index == numRows-1:
                    goUp = True            

        for string in listRow:
            result += ("".join(string))
        return result

sol = Solution()
x = sol.convert("AB", 1)
print(x)