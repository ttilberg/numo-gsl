<%
set name: "new"
set singleton: true
%>
/*
  @overload new

  allocate instance of <%=class_name%> class.

<%= desc %>
 */
static VALUE
<%=c_func(0)%>(VALUE self)
{
    <%=struct%> *w;
    w = <%=func_name%>();
    if (!w) {
        rb_raise(rb_eNoMemError,"fail to allocate struct");
    }
    return TypedData_Wrap_Struct(<%=class_var%>, &<%=data_type_var%>, (void*)w);
}
