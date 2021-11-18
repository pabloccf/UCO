package Ej2;

import java.util.ArrayList;
import java.io.*;
import DAOs.UserDAO;
import java.sql.*;

/**
 * Esta clase es la que se encarga de las funciones principales que puede tener un usuario dentro de nuestro programa
 * @author José Ángel Dorado González, Pablo Ibañez Fernández-Delgado y Pablo López Gosálvez
 * @version openjdk version 11.0.12 2021-07-20
 */

public class UserManager {
	private ArrayList<UserDTO> userList = new ArrayList<UserDTO>();
	//private ArrayList<User> listaUser = new ArrayList<User>();
	private static UserManager instancia = null;
	public static UserManager getUserManager() {
		if(instancia == null) {
			instancia = new UserManager();
		}
		return instancia;
	}
	public TipoUsuario tu;
	
	/**
	 * Esta función se encarga del login del usuario
	 * @param username Es el username del usuario
	 * @param password Es la contraseña del usuario
	 * @return Devuelve true en el caso de que haya podido loguearse de manera correcta y false en el caso contrario
	 */
	public boolean login(String username, String password) {
		//Ver si el usuario esta en la lista
		UserDAO user = new UserDAO();
		userList = user.obtenerTodosUsuarios();
		
		for(int i = 0; i<this.userList.size();i++) {

			if(this.userList.get(i).getUsername().equals(username))
			{
				if(this.userList.get(i).getPassword().equals(password)) {
					return true;
				}
			}	
		}

		return false;
	}

	/**
	 * Esta función se encarga de registrar al usuario
	 * @param usuario Es un objeto de tipo UserDTO que es el usuario 
	 * @throws IOException Señala que se ha producido una excepción de E/S de algún tipo. Esta clase es la clase general de excepciones producidas por operaciones de E/S fallidas o interrumpidas
	 * @throws ClassNotFoundException Es cuando no se encuentra una clase 
	 * @throws SQLException Es cuando hay un error en SQL
	 */
	public void registrar(UserDTO usuario) throws IOException, ClassNotFoundException, SQLException {
		//añadir el usuario a la lista y escribir en el fichero para actualizarlo
        
        UserDAO u = new UserDAO();
        u.create(usuario);
		
	}
	
	/**
	 * Esta función se encarga de buscar y devolver el usuario con el username
	 * @param username Es el username del usuario por el que se va a buscar
	 * @return Devuelve el usuario correspondiente
	 */
	public UserDTO ObtenerUsuario(String username) {
    	//Buscamos el usuario con el username
		
		UserDAO userDAO = new UserDAO();
        return userDAO.buscarUsuarioPorUsername(username);
		
    }
}