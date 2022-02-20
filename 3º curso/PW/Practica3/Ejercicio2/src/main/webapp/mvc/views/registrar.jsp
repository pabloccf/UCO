<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<style>
  .red-text {
    color: red;
  }
</style>
<head>
<meta charset="UTF-8">
<title>Registro</title>
</head>
<body>
	<%
		if(request.getParameter("error") != null) {
	%>
	<p class="red-text">Error! User was not found.</p>
	<%
		}
	%>
	<form method="post" action="../controllers/registrarController.jsp">
		<label for="nombre">Nombre: </label>
		<input type="text" name="nombre">	
		<br/>
		<label for="apellidos">Apellidos: </label>
		<input type="text" name="apellidos">	
		<br/>
		<label for="username">Username: </label>
		<input type="text" name="username">	
		<br/>
		<label for="email">Email: </label>
		<input type="text" name="email">	
		<br/>
		<label for="password">Password: </label>
		<input type="text" name="password">	
		<br/>
		<input type="submit" value="Acceder">
	</form>
</body>
</html>