/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "cal.h"

bool_t
xdr_X_vec (XDR *xdrs, X_vec *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->n))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->X.X_val, (u_int *) &objp->X.X_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_product (XDR *xdrs, product *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->n))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->X.X_val, (u_int *) &objp->X.X_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->Y.Y_val, (u_int *) &objp->Y.Y_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_mean (XDR *xdrs, mean *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->n))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->X.X_val, (u_int *) &objp->X.X_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->Y.Y_val, (u_int *) &objp->Y.Y_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_r_product (XDR *xdrs, r_product *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->n))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->r))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->X.X_val, (u_int *) &objp->X.X_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->Y.Y_val, (u_int *) &objp->Y.Y_len, ~0,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_mean_table (XDR *xdrs, mean_table *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->XY.XY_val, (u_int *) &objp->XY.XY_len, 2,
		sizeof (float), (xdrproc_t) xdr_float))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_product_table (XDR *xdrs, product_table *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->rXY.rXY_val, (u_int *) &objp->rXY.rXY_len, ~0,
		sizeof (float), (xdrproc_t) xdr_float))
		 return FALSE;
	return TRUE;
}
