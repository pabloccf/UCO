package Ejerc1.src.Display;

public class CustomerBean implements java.io.Serializable {

	private static final long serialVersionUID = 1L;

	private String nombre;
	private String apellidos;
	private String username;
	private String email;
	private String password;
	private String tipoUser;
	
	public CustomerBean() {
		this.nombre = "";
		this.apellidos = "";
		this.username = "";
		this.email = "";
		this.password = "";
		this.tipoUser = "";
	}
	
	public String getNombre() {
		return nombre;
	}
	
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public String getApellidos() {
		return apellidos;
	}

	public void setApellidos(String apellidos) {
		this.apellidos = apellidos;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}
	
	public void setTipoAsString(String tipoUser) {
		this.tipoUser = tipoUser;
	}

	public String getTipoAsString() {
		return tipoUser;
	}
}

