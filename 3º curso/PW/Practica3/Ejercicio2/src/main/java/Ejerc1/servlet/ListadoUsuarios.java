package Ejerc1.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
//import javax.servlet.http.HttpSession;

import Ejerc1.src.DAOs.UserDAO;
import java.util.ArrayList;
//import java.io.*;
import Ejerc1.src.Ej2.UserDTO;

/**
 * Servlet encargado de ver el listado de los usuarios registrados
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/ListadoUsuarios")
public class ListadoUsuarios extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public ListadoUsuarios() {
		super();
	}

	/**
	 * Esta función del servlet llama a las funciones necesarias de UserDAO que se
	 * encargan de devolver una lista de todos los usuarios registrados en la base
	 * de datos
	 * 
	 * @param user es el objeto de tipo UserDAO que se encarga de dar acceso a las
	 *             diferentes funciones del usuario
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			UserDAO user = new UserDAO();
			ArrayList<UserDTO> userList = user.obtenerTodosUsuarios();

			// HttpSession session = request.getSession();

			// response.setContentType("text/html");

			PrintWriter salida = response.getWriter();
			salida.println("<html>");
			salida.println("<title>Listado Usuarios</title>");

			salida.println("<body>");
			// salida.println("[");
			salida.println("<p>Listado de usuarios registrados:</p>");

			for (int i = 0; i < userList.size(); i++) {
				/**
				 * salida.println("{");
				 * salida.println("\"nombre\":\""+userList.get(i).getNombre()+"\",");
				 * salida.println("\"apellidos\":\""+userList.get(i).getApellidos()+"\",");
				 * salida.println("\"username\":\""+userList.get(i).getUsername()+"\",");
				 * salida.println("\"email\":\""+userList.get(i).getEmail()+"\",");
				 * salida.println("\"tipoUser\":\""+userList.get(i).getTipoAsString()+"\",");
				 * salida.println("\"fechaRegistro\":\""+userList.get(i).getFecha()+"\"");
				 * salida.println(i==userList.size()-1 ? "}" : "},");
				 **/

				salida.println("<p>Nombre: " + userList.get(i).getNombre());
				salida.println("<br>");
				salida.println("Apellidos: " + userList.get(i).getApellidos());
				salida.println("<br>");
				salida.println("Username: " + userList.get(i).getUsername());
				salida.println("<br>");
				salida.println("Email: " + userList.get(i).getEmail());
				salida.println("<br>");
				salida.println("Tipo de usuario: " + userList.get(i).getTipoAsString());
				salida.println("<br>");
				salida.println("Fecha de registro: " + userList.get(i).getFecha() + "</p>");
			}

			salida.println("</body></html>");
			RequestDispatcher dispatcher = request.getRequestDispatcher("plantilla.html");
			dispatcher.include(request, response);

			// salida.println("]");

			// salida.close();
			// session.setAttribute("userDTO", userDTO);

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {

	}
}