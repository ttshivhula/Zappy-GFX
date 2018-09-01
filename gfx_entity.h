#ifndef GFX_ENTITY_H
# define GFX_ENTITY_H

/*
** == IMPORTANT NOTE ==
** Server will be sending map information 60 times in a second
**
** == HOW DATA WILL BE SENT ==
** Before each set of structs is sent an integer will be sent represent the amount of structs to read.
** all gfx_ent structs,
** all gfx_client structs,
** all gfx_broadcast structs.
**
** Pseudocode to represent more or less what I mean
**
** send(12, sizeof(int));
** send(t_gfx_ent[12], sizeof(t_gfx_ent) * 12);
** send(6, sizeof(int));
** send(t_gfx_client[3], sizeof(t_gfx_client) * 6));
** send(4, sizeof(int));
** send(t_gfx_broadcast[2], sizeof(t_gfx_broadcast) * 4);
**
*/

/*
** Basic gfx entity for most food and stones
**
** == Object types ==
** - "linemate"
** - "deraumere"
** - "sibur"
** - "mendiane"
** - "phiras"
** - "thystame"
** - "food"
**
*/

typedef struct	s_gfx_ent
{
	char	name[16]; // Object type (identifier)
	int		x;
	int		y;
	int		width;
	int		height;
	int		amount; // How much of this can still be mined
}				t_gfx_ent;

typedef struct	s_invent
{
	int	linemate;
	int	deraumere;
	int	sibur;
	int	mendiane;
	int	phiras;
	int	thystame;
	int	food;
}				t_invent;

/*
** == IMPORTANT ACTION NOTE ==
** The developers of the graphical client won't have to concern themselves with the time it takes to perform a take
** I'm just adding it in the comments so that the developers of the server can easily keep track of all actions and how long it takes to complete
*/

typedef enum e_action
{
	ACT_STAND = 0,		// Client not doing anything
	ACT_INV,			// Client viewing inventory takes 1s
	ACT_SEE,			// Client looking around, takes 7s
	ACT_PUT,			// Client placing item on ground, takes 7s
	ACT_GET,			// Client picking up item off ground takes 7s
	ACT_KICK,			// Client kicking other clients away, takes 7s
	ACT_BROADCAST,		// Client broadcasting message, takes 7s
	ACT_INCANTATION,	// Client elevating takes 300s
	ACT_FORK,			// Client lays egg for new client takes 42s
	ACT_HATCH,			// Only affects layed egg, egg hatches into new player client takes 600s
	ACT_DEAD			// Client dead
}			t_action;

/*
** == Orientation notes ==
** Represent which direction an entity is facing 0° - 360°
** 0°   - up
** 90°  - right
** 180° - down
** 270° - left
*/

typedef struct	s_gfx_client
{
	char		name[16];
	int			level;			// Level of the client
	int			orientation;	// Read orientation notes
	t_action	action;			// Used to display what action the client is performing
	t_invent	inventory;
	int 		x;
	int			y;
	int 		width;
	int			height;
}				t_gfx_client;

typedef struct	s_gfx_broadcast
{
	char		message[64];
	int			orientation;	// Read orientation notes
	int			x;
	int			y;
	int			width;
	int			height;
}				t_gfx_broadcast;

#endif
