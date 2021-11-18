package Practica1;

/**
 * Esta clase contiene el constructor, los get y los set del usuario.
 * @author Pablo Ibañez
 * @version openjdk 11.0.11 2021-04-20
*/
public class User {

		private String nombre;
		private String apellidos;
		private String username;
		private String email;
		private String password;
		
		/**
		 * Constructor de los datos del usuario
		 * @param nombre Es el nombre del usuario
		 * @param apellidos Son los apellidos del usuario
		 * @param username Es el nick del usuario
		 * @param email Es el email del usuario
		 * @param password Es la contraseña del usuario
		 */
		public User(String nombre, String apellidos, String username, String email, String password) {
			super();
			this.nombre = nombre;
			this.apellidos = apellidos;
			this.username = username;
			this.email = email;
			this.password = password;
		}
		
		/**
		 * Constructor vacío de los datos del usuario
		 */
		public User() {
			this.nombre = "";
			this.apellidos = "";
			this.username = "";
			this.email = "";
			this.password = "";
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
		 * @return La contraseña del usuario
		 */
		public String getPassword() {
			return password;
		}

		/**
		 * Método que establece un valor a la contraseña del usuario
		 * @param password Es la contraseña que el usuario introduce por pantalla
		 */
		public void setPassword(String password) {
			this.password = password;
		}

		/**
		 * Método que devuelve los apellidos del usuario
		 * @return Los apellidos del usuario
		 */
		public String getApellidos() {
			return apellidos;
		}

		/**
		 * Método que establece un valor a los apellidos del usuario
		 * @param apellidos Son los apellidos que el usuario introduce por pantalla
		 */
		public void setApellidos(String apellidos) {
			this.apellidos = apellidos;
		}

		/**
		 * Método que devuelve el nick del usuario
		 * @return El nick del usuario
		 */
		public String getUsername() {
			return username;
		}

		/**
		 * Método que establece un valor al nick del usuario
		 * @param username Es el nick del usuario que introduce por pantalla
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
}
