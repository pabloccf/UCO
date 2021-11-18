<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<jsp:useBean  id="User" scope="session" class="Ejerc1.src.Ej2.UserDTO"></jsp:useBean>
<%@ page import="Ejerc1.src.Ej2.UserDTO" %>
<%@ page import="Ejerc1.src.Ej2.UserManager" %>
<%@ page import="java.time.ZonedDateTime" %>
<%@ page import="java.text.SimpleDateFormat" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.time.format.DateTimeFormatter" %>
<%@ page import="java.time.LocalDateTime" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Practica 2 PW</title>
</head>
<body>
	<%
		if(request.getParameter("disconnect") != null) {
	%>
	<jsp:setProperty property="username" value="" name="User"/>
	<%
	%>
	<jsp:setProperty property="password" value="" name="User"/>
	<%
		}
		if(User.getUsername() == "" || User.getUsername() == null) {
	%>
		<p><a href="/Ejercicio2/mvc/controllers/loginController.jsp">Acceder</a></p>
		<p><a href="/Ejercicio2/mvc/controllers/registrarController.jsp">Registrarse</a></p>
	<%
		} else {
			session.setAttribute("message", "new");
			UserManager userManager = new UserManager();
			UserDTO user = new UserDTO(); 
			user = userManager.ObtenerUsuario(User.getUsername());
		    DateTimeFormatter dtf2 = DateTimeFormatter.ofPattern("yy/MM/dd HH:mm:ss");
			if(user.getTipoAsString().equals("ESPECTADOR")) {
	%>
	<p><% out.println(user.getUsername() + " / " + user.getTipoAsString()); %></p>
	<p>¡Bienvenido <%out.println(user.getNombre());%>!</p>
	<p>Hoy es <%out.println(dtf2.format(LocalDateTime.now())); %></p>
	<a href="/Ejercicio2/mvc/controllers/desconectarController.jsp">Desconectar</a>
	<%
			} else if(user.getTipoAsString().equals("ADMINISTRADOR")) {
	%>
	<p><% out.println(user.getUsername() + " / " + user.getTipoAsString()); %></p>
	<p>¡Bienvenido <%out.println(user.getNombre());%>!</p>
	<p>Hoy es <%out.println(dtf2.format(LocalDateTime.now())); %></p>
	<%
				//}
	%>
	<a href="/Ejercicio2/mvc/controllers/desconectarController.jsp">Desconectar</a>
	<%
			} else {
				%>
				Error?
				<%
			}
		}
	%>
</body>
</html>