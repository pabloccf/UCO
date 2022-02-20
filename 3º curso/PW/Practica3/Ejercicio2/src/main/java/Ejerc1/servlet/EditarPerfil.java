package Ejerc1.servlet;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.DAOs.UserDAO;
import Ejerc1.src.Ej2.UserDTO;

/**
 * Servlet encargado de editar perfil
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/EditarPerfil")
public class EditarPerfil extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public EditarPerfil() {
		super();
		// TODO Auto-generated constructor stub
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.sendRedirect("/Ejercicio2/editProfile.html");
	}

	/**
	 * Esta función del servlet es la que utiliza las funciones de UserDAO para
	 * pedir la nueva informacion del perfil del usuario y sustituirla por la
	 * antigua
	 * 
	 * @param user  es el objeto tipo UserDAO que se utiliza para acceder a las
	 *              funciones del usuario
	 * @param user1 es el objeto tipo UserDTO que se utiliza para guardar la
	 *              informacion del usuario
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			String nombre = request.getParameter("nombre");
			String apellidos = request.getParameter("apellidos");
			String email = request.getParameter("email");
			String oldPassword = request.getParameter("oldPassword");
			String newPassword = request.getParameter("newPassword");

			UserDAO user = new UserDAO();
			UserDAO u = new UserDAO();
			UserDTO user1 = new UserDTO();

			ArrayList<UserDTO> listaUsuarios = user.obtenerTodosUsuarios();

			for (int i = 0; i < listaUsuarios.size(); i++) {
				if (listaUsuarios.get(i).getUsername().equals((String) request.getSession().getAttribute("username"))) {
					user1.setApellidos(listaUsuarios.get(i).getApellidos());
					user1.setNombre(listaUsuarios.get(i).getNombre());
					user1.setEmail(listaUsuarios.get(i).getEmail());
					user1.setPassword(listaUsuarios.get(i).getPassword());
					user1.setUsername(listaUsuarios.get(i).getUsername());
					user1.setFecha(listaUsuarios.get(i).getFecha());
					user1.setTipoAsString(listaUsuarios.get(i).getTipoAsString());
					u.eliminarUsuario(user1);
				}
			}

			if (!nombre.equals("")) {
				user1.setNombre(nombre);
			}

			if (!apellidos.equals("")) {
				user1.setApellidos(apellidos);
			}

			if (!email.equals("")) {
				user1.setEmail(email);
			}

			if ((!oldPassword.equals("")) && (!newPassword.equals(""))) {
				if (oldPassword.equals(user1.getPassword())) {
					user1.setPassword(newPassword);
				}
			}

			u.create(user1);

			if (user1.getTipoAsString().equals("ADMINISTRADOR")) {
				response.sendRedirect("/Ejercicio2/VentanaEditarPerfilPrincipal.html");
			} else {
				response.sendRedirect("/Ejercicio2/VentanaEditarPerfilEspectador.html");
			}

		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
