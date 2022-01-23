package hello.hellospring.repository;

import hello.hellospring.domain.Member;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.List;

public class MemoryMemberRepositoryTest {
    MemoryMemberRepository repository = new MemoryMemberRepository();

    // 중요 : 모든 테스트는 순서 상관없이 실행되도록 설계해야 함.
    // 그러나 ex) findAll -> repository에 객체가 저장됨
    // 이후 다른 테스트에서 사용하면 오류!!
    // 테스트마다 클리어 해줘야 함.
    // @AfterEach는 매 테스트 이후 실행함.
    @AfterEach
    public void afterEach() {
        repository.clearStore();
    }

    @Test
    public void save() {
        Member member = new Member();
        member.setName("spring");
        repository.save(member);
        // optional은 값을 가져올 때 get()으로 꺼냄. 보통은 한번에꺼내진않음
        Member result = repository.findById(member.getId()).get();

        // 비교 1
        Assertions.assertEquals(member,result); // (기댓값,비교값)

        // 비교 2
//        Assertions.assertThat(member).isEqualTo(result);

        // 실무에서는 오류 빌드할때 오류 테스트케이스 안넘어가면 막아버림
    }

    @Test
    public void findByName() {
        Member member1 = new Member();
        member1.setName("spring1");
        repository.save(member1);

        Member member2 = new Member();
        member2.setName("spring2");
        repository.save(member2);

        Member result = repository.findByName("spring1").get();
        Assertions.assertEquals(member1,result);
    }

    @Test
    public void findAll() {
        Member member1 = new Member();
        member1.setName("spring1");
        repository.save(member1);

        Member member2 = new Member();
        member2.setName("spring1");
        repository.save(member2);

        List<Member> result = repository.findAll();
        Assertions.assertEquals(2, result.size());
    }
}
