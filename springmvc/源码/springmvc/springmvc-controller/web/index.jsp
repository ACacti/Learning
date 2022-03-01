<%--
  Created by IntelliJ IDEA.
  User: ShangJin
  Date: 2020/2/24
  Time: 21:47
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
  <form action="${pageContext.request.contextPath}/user4" method="post">
    id: <input type="text" name="id"><br>
    name: <input type="text" name="name"><br>
    password: <input type="text" name="password"><br>
    <input type="submit">
  </form>
  </body>
</html>
