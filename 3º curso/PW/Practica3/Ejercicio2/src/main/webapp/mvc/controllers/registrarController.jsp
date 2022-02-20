<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<jsp:useBean  id="User" scope="session" class="Ejerc1.src.Ej2.UserDTO"></jsp:useBean>
<%@ page import="Ejerc1.src.Ej2.UserManager" %>
<%@ page import="Ejerc1.src.Ej2.UserDTO" %>
<%@ page import="java.time.LocalDateTime" %>
<%@ page import="java.time.format.DateTimeFormatter" %>
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
		
		DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
		
		String nombre = request.getParameter("nombre");
		String apellidos = request.getParameter("apellidos");
		String username = request.getParameter("username");
		String password = request.getParameter("password");
		String email = request.getParameter("email");
		String tipo = "ESPECTADOR"; //request.getParameter("tipoUsuario");
		String fecha = dtf.format(LocalDateTime.now());

		System.out.println(nombre + " " + apellidos + " " + username + " " + password + " " + email + " " + tipo);
	
		UserManager userManager = new UserManager();
		System.out.println(userManager.login(username, password));
		if(userManager.login(username, password) == false && email != null && nombre != null && apellidos != null && username != null && password != null && tipo != null && fecha != null)  {
			UserDTO usuario = new UserDTO();
			usuario.setNombre(nombre);
			usuario.setApellidos(apellidos);
			usuario.setUsername(username);
			usuario.setPassword(password);
			usuario.setEmail(email);
			usuario.setTipoAsString(tipo);
			usuario.setFecha(fecha);
			userManager.registrar(usuario);
			nextPage = "../../index.jsp";
			nextPageMessage = "";
	%>
	<jsp:setProperty property="nombre" value="<%=nombre%>" name="User"/>
	<jsp:setProperty property="apellidos" value="<%=password%>" name="User"/>
	<jsp:setProperty property="username" value="<%=username%>" name="User"/>
	<jsp:setProperty property="password" value="<%=password%>" name="User"/>
	<jsp:setProperty property="email" value="<%=email%>" name="User"/>
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