#### 栈 + 思维
* 涉及括号匹配，容易想到栈的数据结构
* 每次遇到左括号入栈，遇到字符需要把从当前位置开始连续的字符串入栈，否则，遇到右括号说明此时括号匹配，需要做括号内字符翻转，这里有一定的思维坑，可以写几个样例感受一下翻转的逻辑；遇右出栈直到栈空或者左括号，依次把过程中的每个字符串reverse，然后连接起来，重新放到栈中，以便下一次翻转
* 时间复杂度：O(n) 空间复杂度：O(n)