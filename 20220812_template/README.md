1.模板的语法

```c++
template<class T>
函数声明或定义
```

2.模板使用注意事项

>1.自动类型推导，必须能推导出一致的数据类型T才可使用
>
>2.模板必须要确定出T的数据类型，才可以使用（如果template后跟的函数没有形参，在调用函数的时候需要显示输入任一数据类型，以指定T的数据类型）

3.快速排序原理

首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。