package hello.hellospring.domain;

public class Member {

    private Long id; // 도메인 구분을 위한 시스템이 저장한 id
    private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }
}
