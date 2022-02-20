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
		String nextPage = "../views/login.jsp";
		String nextPageMessage = null;
		
		String username = request.getParameter("username");
		String password = request.getParameter("password");

		UserManager userManager = new UserManager();
		if(userManager.login(username, password) == true) {
			nextPage = "../../index.jsp";
			nextPageMessage = "";
	%>
	<jsp:setProperty property="username" value="<%=username	%>" name="User"/>
	<jsp:setProperty property="password" value="<%=password	%>" name="User"/>
	
	<%
		} else if(username != null) { 
			nextPageMessage = "error";
	%>
	
	<%
		} 
		
		else if(password != null) { 
			nextPageMessage = "error";
	%>
	
	<%
		} else {
	%>
	<jsp:setProperty property="username" value="" name="User"/>
	<%
	%>
	<jsp:setProperty property="password" value="" name="User"/>
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
	} 
	if(password != null) {
%>
<jsp:forward page="<%=nextPage%>">
	    <jsp:param name="error" value="<%=nextPageMessage%>"/>
</jsp:forward>
<%
	}
	else {
%>
<jsp:forward page="<%=nextPage%>" />
<% 
	}
%>