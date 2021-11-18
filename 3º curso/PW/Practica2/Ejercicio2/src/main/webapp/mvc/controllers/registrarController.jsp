<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<jsp:useBean  id="User" scope="session" class="Ejerc1.src.Ej2.UserDTO"></jsp:useBean>
<%@ page import="Ejerc1.src.Ej2.UserManager" %>
<%@ page import="Ejerc1.src.Ej2.UserDTO" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Cargando...</title>
</head>
<body>
	<%
		String nextPage = "../views/registrar.jsp";
		String nextPageMessage = null;
		
		String nombre = request.getParameter("nombre");
		String apellidos = request.getParameter("apellidos");
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String email = request.getParameter("email");
		String tipoUsuario = request.getParameter("tipoUsuario");

	
		UserManager userManager = new UserManager();
		if(userManager.login(username, password) == false && email != null && nombre != null && apellidos != null && username != null && password != null && tipoUsuario != null)  {
			UserDTO usuario = new UserDTO();
			usuario.setNombre(nombre);
			usuario.setApellidos(apellidos);
			usuario.setUsername(username);
			usuario.setPassword(password);
			usuario.setEmail(email);
			usuario.setTipoAsString(tipoUsuario);
			userManager.registrar(usuario);
			nextPage = "../../index.jsp";
			nextPageMessage = "";
	%>
	<jsp:setProperty property="nombre" value="<%=nombre%>" name="User"/>
	<jsp:setProperty property="apellidos" value="<%=password%>" name="User"/>
	<jsp:setProperty property="username" value="<%=username%>" name="User"/>
	<jsp:setProperty property="password" value="<%=password%>" name="User"/>
	<jsp:setProperty property="email" value="<%=email%>" name="User"/>
	<jsp:setProperty property="tipoUsuario" value="<%=tipoUsuario%>" name="User"/>
	<%
			
		} else { 
			nextPageMessage = "error";
	%>
	<jsp:setProperty property="nombre" value="<%=nombre%>" name="User"/>
	<jsp:setProperty property="apellidos" value="<%=password%>" name="User"/>
	<jsp:setProperty property="username" value="<%=username%>" name="User"/>
	<jsp:setProperty property="password" value="<%=password%>" name="User"/>
	<jsp:setProperty property="email" value="<%=email%>" name="User"/>
	<%
		}
	%>
</body>
</html>
<%
	if(username != null) {
%>
<jsp:forward page="<%=nextPage%>">
	    <jsp:param name="error" value="<%=nextPageMessage%>"/>
</jsp:forward>
<%
	} else if(password != null) { 
		nextPageMessage = "error";
%>

<%
	} else {
%>
<jsp:forward page="<%=nextPage%>" />
<% 
	}
%>