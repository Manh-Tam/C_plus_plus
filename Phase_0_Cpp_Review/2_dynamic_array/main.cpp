#include <iostream>

struct linked_list
{
    int data;
    linked_list *p;
};

void linked_list_add_element(linked_list *ll, int data)
{
    linked_list *p_new = new linked_list{data, NULL};
    linked_list *p_temp = ll;
    while (p_temp->p != NULL)
    {
        p_temp = p_temp->p;
    }
    p_temp->p = p_new;
}

void linked_list_print(const linked_list *ll)
{
    if (ll != NULL)
    {
        const linked_list *p_temp = ll;
        do
        {
            std::cout<< p_temp->data << " ";
            p_temp = p_temp->p;
        } while (p_temp != NULL);
        std::cout << std::endl;
    }
}

int main()
{
    linked_list *p_ll = new linked_list;
    p_ll->data = 1;
    p_ll->p = NULL;

    linked_list_print(p_ll);

    linked_list_add_element(p_ll, 4);
    linked_list_add_element(p_ll, 2);
    linked_list_add_element(p_ll, 1);
    linked_list_print(p_ll);
    return 0;
}