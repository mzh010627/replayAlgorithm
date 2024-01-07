#include"phoneBook.h"
#include<stdlib.h>

enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

int phoneBookMenu()
{
    printf("***********************************\n");
    printf("********1.添加联系人信息***********\n");
    printf("********2.删除指定联系人信息*******\n");
    printf("********3.查找指定联系人信息*******\n");
    printf("********4.修改指定联系人信息*******\n");
    printf("************按0退出程序************\n");
    printf("***********************************\n");

}


/* 判空 */
static int panNull(phoneBookTree *pBstree)
{
    int ret = 0;
    if (pBstree == NULL)
    {
        return NULL_PTR;
    }
    return 0;
}

/* 通讯录初始化 */
int phoneBookTreeInit(phoneBookTree **pBstree, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*printFunc)(ELEMENTTYPE val))
{
    int ret = 0;
    phoneBookTree * bstree = (phoneBookTree *)malloc(sizeof(phoneBookTree) * 1);
    if (bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(bstree, 0, sizeof(phoneBookTree) * 1);
    /* 初始化树 */
    {
        bstree->root = NULL;
        bstree->size = 0;

        /* 钩子函数在这边赋值. */
        bstree->compareFunc = compareFunc;
        /* 钩子函数包装器 自定义打印. */
        bstree->printFunc = printFunc;
    }
    bstree->root = createAVLTreeNewNode(0, NULL);
    if (bstree->root == NULL)
    {
        return MALLOC_ERROR;
    }
    *pBstree = bstree;
    return ret;
}

/* 插入新的联系人 */
int phoneBookInsert(phoneBookTree *pBstree, ELEMENTTYPE val)
{
    panNull(*pBstree);

    printf("请输入姓名\n");
    scanf("%s", data->name);

    printf("请输入性别\n");
    scanf("%s",  &data->sex);

    printf("请输入年龄\n");
    scanf("%d",  &data->age);

    printf("请输入电话号码\n");
    scanf("%d",  data->telephone);

    printf("请输入地址\n");
    scanf("%s", data->address);

    balanceBinarySearchTreeInsert(*pBstree,data);
}