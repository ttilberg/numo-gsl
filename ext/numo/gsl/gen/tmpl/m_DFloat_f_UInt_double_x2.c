static void
iter_<%=c_func%>(na_loop_t *const lp)
{
    size_t   i;
    char    *p1, *p2;
    ssize_t  s1, s2;
    unsigned int x;
    double   y;
    double  *opt;
    double   c1, c2;

    INIT_COUNTER(lp, i);
    INIT_PTR(lp, 0, p1, s1);
    INIT_PTR(lp, 1, p2, s2);

    opt = (double*)(lp->opt_ptr);
    c1 = opt[0];
    c2 = opt[1];

    for (; i--;) {
        GET_DATA_STRIDE(p1,s1,double,x);
        y = <%=func_name%>(x, c1, c2);
        SET_DATA_STRIDE(p2,s2,double,y);
    }
}

/*
  @overload <%=name%>(<%=args.map{|a| a[1]}.join(",")%>)
  @param  [UInt]     <%=args[0][1]%>
  @param  [Float]    <%=args[1][1]%> parameter
  @param  [Float]    <%=args[2][1]%> parameter
  @return [DFloat]   result

  <%= description %>
*/
static VALUE
<%=c_func(3)%>(VALUE mod , VALUE v0, VALUE v1, VALUE v2)
{
    ndfunc_arg_in_t ain[1] = {{cUI,0}};
    ndfunc_arg_out_t aout[1] = {{cDF,0}};
    ndfunc_t ndf = {iter_<%=c_func%>, STRIDE_LOOP|NDF_EXTRACT, 1,1, ain,aout};
    double opt[2];

    opt[0] = NUM2DBL(v1);
    opt[1] = NUM2DBL(v2);

    return na_ndloop3(&ndf, opt, 1, v0);
}
