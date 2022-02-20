package Ejerc1.src.Ej2;

public class EspectaculoPuntual extends EspectaculoDTO {
	private String fecha;
	private Integer hora;
	
	public EspectaculoPuntual(String titulo, String descripcion, String categoria, Integer aforo, String Fecha, Integer Hora) {
		super(titulo, descripcion, categoria, aforo, 1);
		this.fecha = Fecha;
		this.hora = Hora;
	}
	
	public String getFecha() {
		return fecha;
	}

	public void setFecha(String fecha) {
		this.fecha = fecha;
	}

	public Integer getHoraA() {
		return hora;
	}

	public void setHoraA(Integer hora) {
		this.hora = hora;
	}
}