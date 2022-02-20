package Ejerc1.src.Ej2;


/**
 * Esta clase contiene el constructor, los get y los set de los usuarios.
 * @author Pablo López Gosálvez, Pablo Ibañez Fernández-Delgado y José Ángel Dorado González
 * @version openjdk version 11.0.12 2021-07-20
 */

public class UserDTO {

	private String nombre;
	private String apellidos;
	private String username;
	private String email;
	private String password;
	private String tipoUser;
	private String fecha;
	
	/**
	 * Contructor de los datos del usuario
	 * @param nombre Es el nombre del usuario
	 * @param apellidos Son los apellidos de los usuarios
	 * @param username Es el apodo del usuario
	 * @param email Es el email del usuario
	 * @param password Es la contraseña del usuario
	 * @param tipo Es el tipo que es
	 * @param tipoUser Es el tipo de usuario que es
	 */
	public UserDTO(String nombre, String apellidos, String username, String email, String password, String tipoUser, String fecha) {
		super();
		this.nombre = nombre;
		this.apellidos = apellidos;
		this.username = username;
		this.email = email;
		this.password = password;
		this.tipoUser = tipoUser;
		this.fecha = fecha;
	}
	
	/**
	 * Constructor vacío de los datos de los espectáculos
	 */
	public UserDTO() {
		this.nombre = "";
		this.apellidos = "";
		this.username = "";
		this.email = "";
		this.password = "";
		this.tipoUser = "";
		this.fecha = "";
	}
	
	/**
	 * Método que devuelve el nombre del usuario
	 * @return El nombre del usuario
	 */
	public String getNombre() {
		return nombre;
	}
	
	/**
	 * Método que establece un valor al nombre del usuario
	 * @param nombre Es el nombre del usuario que introduce por pantalla
	 */
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	/**
	 * Método que devuelve la contraseña del usuario
	 * @return Son los apellidos del usuario que introduce por pantalla
	 */
	public String getPassword() {
		return password;
	}

	/**
	 * Método que establece un valor a la contraseña del usuario 
	 * @param password La contraseña del usuario que introduce por pantalla
	 */
	public void setPassword(String password) {
		this.password = password;
	}

	/**
	 * Método que devuelve los apellidos del usuario
	 * @return Son los apellidos del usuario que introduce por pantalla
	 */
	public String getApellidos() {
		return apellidos;
	}

	/**
	 * Método que establece un valor a los apellidos del usuario
	 * @param apellidos Son los apellidos del usuario que introduce por pantalla
	 */
	public void setApellidos(String apellidos) {
		this.apellidos = apellidos;
	}

	/**
	 * Método que devuelve el username del usuario
	 * @return El username del usuario
	 */
	public String getUsername() {
		return username;
	}

	/**
	 * Método que establece un valor al username del usuario
	 * @param username Es el username del usuario que introduce por pantalla
	 */
	public void setUsername(String username) {
		this.username = username;
	}

	/**
	 * Método que devuelve el email del usuario
	 * @return El email del usuario
	 */
	public String getEmail() {
		return email;
	}

	/**
	 * Método que establece un valor al email del usuario
	 * @param email Es el email del usuario que introduce por pantalla
	 */
	public void setEmail(String email) {
		this.email = email;
	}

	/**
	 * Método que establece un valor al tipo de usuario que es 
	 * @param tipoUser Es el tipo de usuario que introduce por pantalla
	 */
	public void setTipoAsString(String tipoUser) {
		this.tipoUser = tipoUser;
	}

	/**
	 * Método que devuelve el tipo de usuario
	 * @return El tipo de usuario
	 */
	public String getTipoAsString() {
		return tipoUser;
	}
	
	public void setFecha(String fecha) {
		this.fecha = fecha;
	}
	
	public String getFecha() {
		return fecha;
	}
}