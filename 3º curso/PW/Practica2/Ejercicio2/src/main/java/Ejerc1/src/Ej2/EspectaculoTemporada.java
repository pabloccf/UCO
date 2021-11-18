package Ejerc1.src.Ej2;

public class EspectaculoTemporada extends EspectaculoDTO {
	private String diaSemana;
	private String fechaInicio;
	private String fechaFin;
	
	public EspectaculoTemporada(String titulo, String descripcion, String categoria, Integer aforo, String DiaSemana, String FechaInicio, String FechaFin) {
		super(titulo, descripcion, categoria, aforo);
		this.diaSemana = DiaSemana;
		this.fechaInicio = FechaInicio;
		this.fechaFin = FechaFin;
	}

	public String getDiaSemana() {
		return diaSemana;
	}

	public void setDiaSemana(String diaSemana) {
		this.diaSemana = diaSemana;
	}

	public String getFechaInicio() {
		return fechaInicio;
	}

	public void setFechaInicio(String fechaInicio) {
		this.fechaInicio = fechaInicio;
	}

	public String getFechaFin() {
		return fechaFin;
	}

	public void setFechaFin(String fechaFin) {
		this.fechaFin = fechaFin;
	}
}