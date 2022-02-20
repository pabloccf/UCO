package Ejerc1.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import Ejerc1.src.DAOs.UserDAO;
import Ejerc1.src.Ej2.UserDTO;
import Ejerc1.src.Ej2.UserManager;

import java.time.format.DateTimeFormatter;
import java.time.LocalDateTime;

/**
 * Servlet encargado de Registrar un usuario
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/Registrar")
public class Registrar extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public Registrar() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * Esta función utiliza funciones del UserDAO para registrar un nuevo usuario
	 * 
	 * @param user  es el objeto del tipo UserDTO el cual va almacenar la
	 *              informacion del nuevo usuario
	 * @param user1 es el objeto del tipo UserDAO va apermitir acceder a las
	 *              funciones del DAO
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		// TODO Auto-generated method stub
		try {
			DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
			String nombre = request.getParameter("nombre");
			String apellidos = request.getParameter("apellidos");
			String email = request.getParameter("email");
			String username = request.getParameter("username");
			String password = request.getParameter("password");
			String tipo = "ESPECTADOR";
			String fecha = dtf.format(LocalDateTime.now());

			UserDTO user = new UserDTO();
			UserDAO user1 = new UserDAO();
			ArrayList<UserDTO> userList = user1.obtenerTodosUsuarios();
			int contadorUsername = 0;

			user.setNombre(nombre);
			user.setApellidos(apellidos);
			user.setEmail(email);
			user.setUsername(username);
			user.setPassword(password);
			user.setTipoAsString(tipo);
			user.setFecha(fecha);

			UserManager userManager = new UserManager();

			PrintWriter salida = response.getWriter();

			for (int i = 0; i < userList.size(); i++) {
				if (userList.get(i).getUsername().equals(user.getUsername())) {
					contadorUsername++;
				}
			}

			if (contadorUsername == 0) {
				userManager.registrar(user);
				salida.println("Registro completado correctamente");
				response.sendRedirect("/Ejercicio2/iniciarSesio.html");
			}

			else {
				salida.println("Error, ese username ya esta registrado");
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
