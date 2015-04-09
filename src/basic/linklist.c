#include "linklist.h"
#include "tools.h"
#include "def.h"
#include "log.h"


static int	P2P_LL_pushback_data( LLData_s *linklist, void *data );
static int	P2P_LL_pushfront_data( LLData_s *linklist, void *data );
static int	P2P_LL_first_add_data( LLData_s *linklist, void *data );



/***********************************************************
	pushback functions.
************************************************************/
LINKLIST_PUSHBACK_FUNCTION(LLTest)

	
/***********************************************************
	pushfront functions.
************************************************************/
LINKLIST_PUSHFRONT_FUNCTION(LLTest)


	
/***********************************************************
	get node functions.
************************************************************/
LINKLIST_GET_NODE_FUNCTION(LLTest)




/***********************************************************
	P2P_LL_first_add_data
************************************************************/
static int	P2P_LL_first_add_data( LLData_s *linklist, void *data )
{
	if( linklist->head != NULL || linklist->tail != NULL || linklist->node != NULL )
	{
		ALARM_LOG("linklist push data ptr is not NULL.")
		return	P2P_ERROR;
	}
	linklist->head	=	(Node_s*)P2P_malloc( sizeof(Node_s) );
	linklist->head->next	=	NULL;
	linklist->head->prev	=	NULL;
	linklist->head->data	=	data;

	linklist->tail	=	linklist->head;
	linklist->node	=	linklist->head;
	linklist->size++;

	return	P2P_OK;
}


/***********************************************************
	P2P_LL_pushfront_data
************************************************************/
static int	P2P_LL_pushfront_data( LLData_s *linklist, void *data )
{	
	int		err;

	// first push data.
	if( linklist->size == 0 )
	{
		err		=	P2P_LL_first_add_data( linklist, data );
		return	err;
	}
	// add to head.
	else
	{
		Node_s	*new_node	=	NULL;
		Node_s	*next_node	=	NULL;

		if( linklist->head == NULL )
		{
			ALARM_LOG("linklist push data haed is NULL.")
			return	P2P_ERROR;
		}
		//
		new_node	=	(Node_s*)P2P_malloc( sizeof(Node_s) );
		if( new_node == NULL )
		{
			ALARM_LOG("linklist push data node malloc fail.")
			return	P2P_ERROR;
		}
		//
		next_node	=	linklist->head;
		linklist->head->prev	=	new_node;
		linklist->head	=	linklist->head->prev;
		linklist->head->prev	=	NULL;
		linklist->head->next	=	next_node;
		linklist->size++;		

		return	P2P_OK;
	}
}



/***********************************************************
	P2P_LL_push_data
************************************************************/
static int	P2P_LL_pushback_data( LLData_s *linklist, void *data )
{
	int		err;

	// first push data.
	if( linklist->size == 0 )
	{
		err		=	P2P_LL_first_add_data( linklist, data );
		return	err;
	}
	// add to tail.
	else
	{
		Node_s	*new_node	=	NULL;
		Node_s	*prev_node	=	NULL;

		if( linklist->head == NULL )
		{
			ALARM_LOG("linklist push data haed is NULL.")
			return	P2P_ERROR;
		}
		//
		new_node	=	(Node_s*)P2P_malloc( sizeof(Node_s) );
		if( new_node == NULL )
		{
			ALARM_LOG("linklist push data node malloc fail.")
			return	P2P_ERROR;
		}
		//
		new_node->data	=	data;
		prev_node	=	linklist->tail;
		linklist->tail->next	=	new_node;
		linklist->tail	=	linklist->tail->next;
		linklist->tail->next	=	NULL;
		linklist->tail->prev	=	prev_node;
		linklist->size++;		

		return	P2P_OK;
	}
}



/***********************************************************
	P2P_LL_set_node_to_head
************************************************************/
void	P2P_LL_set_node_to_head( LLData_s *linklist )
{
	if( linklist == NULL )
	{
		ALARM_LOG("linklist == NULL")
		return;
	}
	if( linklist->head == NULL )
		WARNING_LOG("linklist->head == NULL" )

	linklist->node	=	linklist->head;
}



/***********************************************************
	P2P_LL_set_node_to_tail
************************************************************/
void	P2P_LL_set_node_to_tail( LLData_s *linklist )
{
	if( linklist == NULL )
	{
		ALARM_LOG("linklist == NULL")
		return;
	}
	if( linklist->tail == NULL )
		WARNING_LOG("linklist->head == NULL" )

	linklist->node	=	linklist->tail;
}



/***********************************************************
	P2P_LL_move_to_next
************************************************************/
void	P2P_LL_move_to_next( LLData_s *linklist )
{
	if( linklist == NULL )
	{
		ALARM_LOG("linklist == NULL")
		return;
	}
	if( linklist->node == NULL )
	{
		ALARM_LOG("linklist->node == NULL")
		return;
	}
	
	if( linklist->node->next == NULL )
	{
#if defined(_DEBUG) | defined(DEBUG)
		if( linklist->node != linklist->tail )
			WARNING_LOG("linklist node at tail but not equal tail.")
#endif
		WARNING_LOG("linklist node at tail.")
		return;
	}

	// move to next.
	linklist->node	=	linklist->node->next;
}




/***********************************************************
	P2P_LL_move_to_prev
************************************************************/
void	P2P_LL_move_to_prev( LLData_s *linklist )
{
	if( linklist == NULL )
	{
		ALARM_LOG("linklist == NULL")
		return;
	}
	if( linklist->node == NULL )
	{
		ALARM_LOG("linklist->node == NULL")
		return;
	}
	
	if( linklist->node->prev == NULL )
	{
#if defined(_DEBUG) | defined(DEBUG)
		if( linklist->node != linklist->head )
			WARNING_LOG("linklist node at head but not equal head.")
#endif
		WARNING_LOG("linklist node at head.")
		return;
	}

	// move to next.
	linklist->node	=	linklist->node->prev;
}



/***********************************************************
	P2P_LL_size
************************************************************/
int		P2P_LL_size( LLData_s *linklist )
{
	if( linklist == NULL )
	{
		ALARM_LOG("linklist is NULL")
			return	P2P_ERROR;
	}

	return	linklist->size;
}



/***********************************************************
	P2P_LL_remove_node
************************************************************/
void	P2P_LL_remove_node( LLData_s *linklist )
{
	if( linklist == NULL )
	{
		ALARM_LOG("linklist == NULL")
		return;
	}

	if( linklist->node == NULL )
	{
		WARNING_LOG("linklist->node == NULL")
		return;
	}

	if( linklist->size == 1 )
	{
		P2P_free( linklist->node );
		linklist->head	=	NULL;
		linklist->tail	=	NULL;
		linklist->node	=	NULL;
	}
	else
	{
		if( linklist->node == linklist->head )
		{
			linklist->head	=	linklist->head->next;
			linklist->node	=	(Node_s*)P2P_free( linklist->node );
			linklist->head->prev	=	NULL;
			linklist->node	=	linklist->head;
		}
		else if( linklist->node == linklist->tail )
		{
			linklist->tail	=	linklist->tail->prev;
			linklist->node	=	(Node_s*)P2P_free( linklist->node );
			linklist->tail->next	=	NULL;
			linklist->node	=	linklist->tail;
		}
		else
		{
			Node_s	*p_tmp	=	linklist->node;
			linklist->node	=	linklist->node->next;
			linklist->node->prev	=	p_tmp->prev;
			linklist->node->prev->next	=	linklist->node;
			P2P_free(p_tmp);
		}
	}

	linklist->size--;

	if( linklist->size < 0 )
		ALARM_LOG("linklist->size < 0")
}



/***********************************************************
	P2P_LL_is_empty
************************************************************/
bool	P2P_LL_is_empty( LLData_s *linklist )
{
	if( linklist == NULL )
	{
		WARNING_LOG("linklist == NULL")
		return	true;
	}

	if( linklist->size == 0 )
		return	true;
	else
		return	false;
}



/***********************************************************
	P2P_LL_init
************************************************************/
LLData_s*	P2P_LL_init( LL_TYPE_e type )
{
	LLData_s	*ptr	=	NULL;	

	ptr		=	(LLData_s*)P2P_malloc( sizeof(LLData_s) );
	if( ptr == NULL )
		ALARM_LOG("P2P_LL_init fail.")
	else
	{
		ptr->head	=	NULL;
		ptr->node	=	NULL;
		ptr->tail	=	NULL;
		ptr->type	=	type;
		ptr->size	=	0;
	}	

	return	ptr;
}



/***********************************************************
	P2P_LL_clear
************************************************************/
void	P2P_LL_clear( LLData_s *linklist )
{
	Node_s	*node	=	linklist->head;
	Node_s	*tmp	=	NULL;

	if( linklist == NULL )
	{
		WARNING_LOG("linklist is NULL")
		return;
	}
	if( linklist->head == NULL )
	{
#if defined(_DEBUG) | defined(DEBUG)
		if( linklist->size > 0 )
			ALARM_LOG("linklist->size > 0")
#endif
		WARNING_LOG("linklist->head is NULL")
		return;
	}

	// loop clear mem.
	while( node->next != NULL )
	{
		tmp		=	node->next;
		P2P_free(node->data);
		P2P_free(node);
		node	=	tmp;
	}
	P2P_free(node->data);
	P2P_free(node);		// clear the last node.

	linklist->size	=	0;
	linklist->head	=	NULL;
	linklist->tail	=	NULL;
	linklist->node	=	NULL;
}




/***********************************************************
	P2P_LL_free
************************************************************/
LLData_s*	P2P_LL_free( LLData_s *linklist )
{
	// need free list data.
	P2P_LL_clear(linklist);

	P2P_free( linklist );
	return	NULL;
}

