package Ejerc1.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import Ejerc1.src.DAOs.UserDAO;
import Ejerc1.src.Ej2.UserDTO;
import Ejerc1.src.Ej2.UserManager;

/**
 * Servlet encargado de iniciar sessión
 * 
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo
 *         López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */
@WebServlet("/IniciarSesion")
public class IniciarSesion extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * Es el constructor del servlet.
	 */
	public IniciarSesion() {
		super();
		// TODO Auto-generated constructor stub
	}

	/**
	 * Esta funcion del servlet se encarga de llamar a las funciones de UserDAO que
	 * comparan e inician la sesion del usuario
	 * 
	 * @param userManager es el objeto del tipo UserManager que se encarga de
	 *                    getsionar el usuario
	 * @param user1       es el objeto de tipo UserDAO que se encarga de
	 *                    proporcionar las funciones necesarias
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún
	 *                     tipo. Esta clase es la clase general de excepciones
	 *                     producidas por operaciones de E/S fallidas o
	 *                     interrumpidas
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		try {
			String username = request.getParameter("username");
			String password = request.getParameter("password");

			UserManager userManager = new UserManager();

			HttpSession session = request.getSession(true);
			//PrintWriter salida = response.getWriter();

			UserDAO user1 = new UserDAO();

			ArrayList<UserDTO> listaUsuarios = new ArrayList<UserDTO>();
			listaUsuarios = user1.obtenerTodosUsuarios();

			if (userManager.login(username, password)) {
				session.setAttribute("username", username);
				session.setAttribute("password", password);
				for (int i = 0; i < listaUsuarios.size(); i++) {
					if (username.equals(listaUsuarios.get(i).getUsername())) {
						if (listaUsuarios.get(i).getTipoAsString().equals("ADMINISTRADOR")) {
							session.setAttribute("tipo", "ADMINISTRADOR");
							response.sendRedirect("/Ejercicio2/MenuPrincipal.html");
						} else {
							session.setAttribute("tipo", "ESPECTADOR");
							response.sendRedirect("/Ejercicio2/MenuPrincipalEspectador.html");
						}
					}
				}

			}

			else {
				RequestDispatcher dispatcher = request.getRequestDispatcher("VentanaCredencialesIncorrectas.html");
				dispatcher.include(request, response);

			}

			// response.sendRedirect(nextPage);

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
