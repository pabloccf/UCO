<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<jsp:useBean  id="User" scope="session" class="Ejerc1.src.Ej2.UserDTO"></jsp:useBean>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Disconnecting...</title>
</head>
<body>

</body>
</html>
<jsp:setProperty property="username" value="" name="User"/>
<jsp:setProperty property="password" value="" name="User"/>
<jsp:forward page="../../index.jsp">
    <jsp:param name="disconnect" value="disconnect"/>
</jsp:forward>