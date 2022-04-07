void	ps_free_tlist_nod(t_list **m, int skip, int nbr)
{
	t_list	*save;
	t_list	*tmp;

	while (skip)
		*m = (*m)->next;
	cut = (*m);
	*m = (*m)->next;
	while (nbr--)
	{
		tmp = *m;
		*m = (*m)->next;
		free(tmp->content);
		free(tmp);
	}
	cut->next = *m
}
/******************************************
 * used in ps_opt_cutnpatch_a / _b
 * skip nod; (deals with remaining ra or rb)
 * free nbr nods of rb;
 * repatch nods;
 ******************************************/
